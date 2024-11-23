#pragma once

#ifndef QUANTUM_ANNEALING_H
#define QUANTUM_ANNEALING_H

#include <vector>
#include <boost/numeric/ublas/matrix.hpp>  // Boost matrix for QUBO

/**
 * @class QuantumAnnealing
 * @brief A class to perform Quantum Annealing to solve QUBO problems.
 * 
 * This class implements the Quantum Annealing algorithm, which is used to solve **Quadratic Unconstrained Binary Optimization (QUBO)** problems.
 * The QUBO problem involves finding a binary vector (a series of 0s and 1s) that minimizes a given quadratic objective function, often represented by a QUBO matrix.
 * Quantum Annealing uses quantum mechanical principles to explore the solution space, converging to the global minimum of the QUBO function.
 */
class QuantumAnnealing {
public:
    /**
     * @brief Constructor for the QuantumAnnealing class.
     * 
     * Initializes the QuantumAnnealing object with the number of qubits (or binary variables) and sets the initial temperature for annealing.
     * The number of qubits defines the dimensionality of the QUBO problem, i.e., the number of binary variables to optimize.
     * 
     * @param num_qubits The number of qubits (or binary variables) in the QUBO problem.
     */
    QuantumAnnealing(int num_qubits);

    /**
     * @brief Solves a QUBO problem using the Quantum Annealing algorithm.
     * 
     * This method uses the Quantum Annealing technique to solve a given QUBO problem, represented by a matrix.
     * It attempts to find the binary vector (state) that minimizes the objective function defined by the QUBO matrix.
     * The annealing process involves gradually reducing the temperature, allowing the system to settle into the ground state (lowest energy configuration).
     * 
     * @param QUBO_matrix The QUBO matrix that defines the objective function to be minimized. This matrix is used to calculate the energy and guide the annealing process.
     * @return A binary vector (vector of 0s and 1s) that represents the solution to the QUBO problem.
     */
    std::vector<int> solveQUBO(const boost::numeric::ublas::matrix<double>& QUBO_matrix);

private:
    int num_qubits;               ///< The number of qubits (binary variables) in the QUBO problem.
    double temperature;           ///< The current temperature for the annealing process.

    /**
     * @brief Performs the annealing process for a given state.
     * 
     * The annealing process involves gradually lowering the temperature to guide the system toward its ground state.
     * At each temperature step, the state of the system is updated based on the energy landscape.
     * 
     * @param state The current state of the system, represented as a binary vector (0s and 1s).
     * @param temperature The current temperature of the system. The temperature is gradually lowered during the annealing process.
     */
    void anneal(std::vector<int>& state, double temperature);

    /**
     * @brief Computes the energy of the given state for a QUBO problem.
     * 
     * The energy is computed based on the binary state and the QUBO matrix. The energy represents the objective function's value for the given state,
     * and it is used to guide the annealing process. The lower the energy, the better the solution.
     * 
     * @param state The current state of the system, represented as a binary vector (0s and 1s).
     * @param QUBO_matrix The QUBO matrix that defines the energy function. It is used to calculate the energy of the state.
     * @return The energy of the current state, based on the QUBO matrix.
     */
    double computeEnergy(const std::vector<int>& state, const boost::numeric::ublas::matrix<double>& QUBO_matrix);
};

#endif // QUANTUM_ANNEALING_H
