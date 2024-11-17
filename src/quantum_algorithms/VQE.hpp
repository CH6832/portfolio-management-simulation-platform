#pragma once

#ifndef VQE_H
#define VQE_H

#include <vector>
#include <ql/quantlib.hpp>  // QuantLib for financial modeling

class VQE {
public:
    VQE(int num_qubits);
    double computeGroundStateEnergy(const std::vector<double>& hamiltonian, const std::vector<double>& initial_params);

private:
    int num_qubits;
    double evaluateHamiltonian(const std::vector<double>& params);
    void optimizeParameters(std::vector<double>& params);
};

#endif // VQE_H
