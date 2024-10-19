#include "QUBOFormulation.h"
#include <iostream>
#include <Eigen/Dense> // Using Eigen for matrix operations

QUBOFormulation::QUBOFormulation(const std::vector<double>& returns, const std::vector<std::vector<double>>& covariance, double riskAversion)
    : expectedReturns(returns), covarianceMatrix(covariance), riskAversion(riskAversion) {}

std::vector<std::vector<double>> QUBOFormulation::formulateQUBO() {
    int n = expectedReturns.size();
    std::vector<std::vector<double>> Q(n, std::vector<double>(n, 0.0));

    // Fill the QUBO matrix
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            Q[i][j] = calculateQUBOCoefficient(i, j);
        }
    }

    return Q;
}

double QUBOFormulation::calculateQUBOCoefficient(int i, int j) {
    if (i == j) {
        return riskAversion * expectedReturns[i] - covarianceMatrix[i][i]; // Diagonal elements
    }
    return -covarianceMatrix[i][j]; // Off-diagonal elements
}
