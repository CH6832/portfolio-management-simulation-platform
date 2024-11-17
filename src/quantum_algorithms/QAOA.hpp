#pragma once

#ifndef QAOA_H
#define QAOA_H

#include <vector>
#include <boost/math/constants/constants.hpp> // Boost for constants

class QAOA {
public:
    QAOA(int num_qubits, int steps);
    void setParameters(const std::vector<double>& gamma, const std::vector<double>& beta);
    double optimize(const std::vector<double>& problem_instance);

private:
    int num_qubits;
    int steps;
    std::vector<double> gamma;
    std::vector<double> beta;
    double computeObjective(const std::vector<int>& solution);

    std::vector<int> runQuantumCircuit();
};

#endif // QAOA_H
