#pragma once

#ifndef QUANTUM_ANNEALING_H
#define QUANTUM_ANNEALING_H

#include <vector>
#include <boost/numeric/ublas/matrix.hpp>  // Boost matrix for QUBO

class QuantumAnnealing {
public:
    QuantumAnnealing(int num_qubits);
    std::vector<int> solveQUBO(const boost::numeric::ublas::matrix<double>& QUBO_matrix);

private:
    int num_qubits;
    double temperature;
    void anneal(std::vector<int>& state, double temperature);
    double computeEnergy(const std::vector<int>& state, const boost::numeric::ublas::matrix<double>& QUBO_matrix);
};

#endif // QUANTUM_ANNEALING_H
