#include "MarkowitzOptimizer.h"
#include <Eigen/Dense>
#include <iostream>

MarkowitzOptimizer::MarkowitzOptimizer(const std::vector<double>& returns, const std::vector<std::vector<double>>& covariance)
    : expectedReturns(returns), covarianceMatrix(covariance) {}

std::vector<double> MarkowitzOptimizer::optimizePortfolio(double riskAversion) {
    int n = expectedReturns.size();
    Eigen::VectorXd weights = Eigen::VectorXd::Zero(n);
    Eigen::MatrixXd covMatrix = Eigen::MatrixXd(n, n);

    // Convert covariance matrix from std::vector to Eigen::MatrixXd
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            covMatrix(i, j) = covarianceMatrix[i][j];
        }
    }

    // Mean-Variance Optimization (simplified)
    // This is a naive implementation and should be improved.
    Eigen::VectorXd expectedReturnsVec = Eigen::VectorXd::Map(expectedReturns.data(), n);
    weights = covMatrix.inverse() * expectedReturnsVec * (1.0 / riskAversion);

    // Normalize weights
    weights = weights / weights.sum();
    return std::vector<double>(weights.data(), weights.data() + weights.size());
}
