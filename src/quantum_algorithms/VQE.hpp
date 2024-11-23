#pragma once

#ifndef VQE_H
#define VQE_H

#include <vector>
#include <ql/math/array.hpp>
#include <ql/math/optimization/endcriteria.hpp>
#include <ql/math/optimization/levenbergmarquardt.hpp>

/**
 * @class VQE
 * @brief A class for the Variational Quantum Eigensolver (VQE) algorithm.
 * 
 * The VQE class is responsible for finding the ground state energy of a quantum system
 * using the variational principle. It optimizes a set of parameters that describe a quantum
 * state, minimizing the expectation value of the Hamiltonian of the system. The VQE algorithm
 * uses classical optimization techniques to search for the optimal parameters.
 */
class VQE {
public:
    /**
     * @brief Constructor for the VQE class.
     * 
     * Initializes the VQE instance with the number of qubits and the Hamiltonian of the quantum system.
     * The Hamiltonian is used in the optimization process to compute the energy of the quantum system.
     * 
     * @param num_qubits The number of qubits in the quantum system.
     * @param hamiltonian A vector representing the Hamiltonian of the system, which is used in the VQE computation.
     */
    VQE(int num_qubits, const std::vector<double>& hamiltonian);

    /**
     * @brief Computes the ground state energy of the quantum system using the VQE algorithm.
     * 
     * This method optimizes the parameters (typically angles in a quantum circuit) to minimize the
     * expectation value of the Hamiltonian. The goal is to find the set of parameters that results in
     * the lowest energy (ground state).
     * 
     * @param hamiltonian A vector representing the Hamiltonian of the system (it could differ from the one used during construction).
     * @param initial_params A vector of initial parameters for the quantum circuit, typically a set of angles for the quantum gates.
     * @return The computed ground state energy.
     */
    double computeGroundStateEnergy(const std::vector<double>& hamiltonian, const std::vector<double>& initial_params);

private:
    int num_qubits;                        ///< The number of qubits in the quantum system.
    std::vector<double> hamiltonian;        ///< The Hamiltonian of the quantum system (used for energy computations).

    /**
     * @brief Evaluates the energy of the quantum system given a set of parameters.
     * 
     * This function computes the expectation value of the Hamiltonian with respect to a quantum state
     * defined by the provided parameters. The energy represents how well the parameters describe the system's state.
     * 
     * @param params A vector of parameters that define the quantum state (typically angles of quantum gates).
     * @return The computed energy (expectation value of the Hamiltonian).
     */
    double evaluateHamiltonian(const std::vector<double>& params);

    /**
     * @brief Optimizes the parameters of the quantum state to minimize the Hamiltonian's expectation value.
     * 
     * This function uses a classical optimization algorithm (Levenberg-Marquardt) to minimize the energy,
     * adjusting the parameters iteratively until convergence. The algorithm aims to find the optimal set of
     * parameters that correspond to the ground state of the system.
     * 
     * @param params A vector of parameters that will be optimized (the initial guess is provided before optimization).
     */
    void optimizeParameters(std::vector<double>& params);
};

#endif // VQE_H
