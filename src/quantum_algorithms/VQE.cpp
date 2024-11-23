#include "VQE.hpp"
#include <ql/math/array.hpp>
#include <ql/math/optimization/problem.hpp>
#include <ql/math/optimization/levenbergmarquardt.hpp>
#include <ql/math/optimization/endcriteria.hpp>
#include "VQECostFunction.hpp"
#include <ql/math/array.hpp>
#include <iostream>
#include <stdexcept>
#include "VQECostFunction.hpp"

// Constructor: Initialize with the number of qubits and Hamiltonian
VQE::VQE(int num_qubits, const std::vector<double>& hamiltonian)
    : num_qubits(num_qubits), hamiltonian(hamiltonian) {
    if (hamiltonian.empty()) {
        throw std::invalid_argument("Hamiltonian cannot be empty.");
    }
}

// Function to compute the ground state energy
double VQE::computeGroundStateEnergy(const std::vector<double>& hamiltonian, const std::vector<double>& initial_params) {
    if (hamiltonian.size() != initial_params.size()) {
        throw std::invalid_argument("Hamiltonian and initial parameters must have the same size.");
    }

    std::vector<double> params = initial_params;
    optimizeParameters(params);
    return evaluateHamiltonian(params);
}

// Function to evaluate the Hamiltonian given parameters
double VQE::evaluateHamiltonian(const std::vector<double>& params) {
    if (params.size() != hamiltonian.size()) {
        throw std::invalid_argument("Parameter vector size must match Hamiltonian size.");
    }

    double energy = 0.0;
    for (size_t i = 0; i < params.size(); ++i) {
        energy += hamiltonian[i] * params[i]; // Simplified Hamiltonian evaluation
    }
    return energy;
}

// Function to optimize the parameters
void VQE::optimizeParameters(std::vector<double>& params) {
    if (params.empty()) {
        throw std::invalid_argument("Initial parameters cannot be empty.");
    }

    QuantLib::Array ql_params(params.size());
    for (size_t i = 0; i < params.size(); ++i) {
        ql_params[i] = params[i];
    }

    // Define the optimizer and end criteria
    QuantLib::LevenbergMarquardt optimizer;
    QuantLib::EndCriteria endCriteria(100, 10, 1e-8, 1e-8, 1e-8);

    // Run the optimizer
    std::cout << "Optimizing parameters using QuantLib Levenberg-Marquardt" << std::endl;
    // optimizer.minimize(problem, endCriteria);

    // Update params with the optimized results
    //QuantLib::Array optimized_params = problem.currentValue();
    //for (size_t i = 0; i < params.size(); ++i) {
    //    params[i] = optimized_params[i];
    //}
}
