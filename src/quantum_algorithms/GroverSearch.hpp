#pragma once

#ifndef GROVER_SEARCH_H
#define GROVER_SEARCH_H

#include <vector>
#include <boost/numeric/ublas/vector.hpp>  // Boost for vector operations

/**
 * @class GroverSearch
 * @brief Implements Grover's Search algorithm for unstructured search problems.
 * 
 * Grover's Search is a quantum algorithm designed to search through an unsorted database of size N in approximately √N steps. 
 * This class provides an implementation of the Grover Search algorithm to search for a target element in a database, 
 * utilizing quantum superposition and amplitude amplification to increase the probability of finding the target.
 * 
 * This implementation assumes a binary database and uses a quantum circuit to perform the search, applying the Grover operator iteratively to amplify the amplitude of the target element.
 */
class GroverSearch {
public:
    /**
     * @brief Constructor for the GroverSearch class.
     * 
     * Initializes the GroverSearch object with the number of qubits used in the quantum system. 
     * The number of qubits corresponds to the number of binary elements in the database.
     * 
     * @param num_qubits The number of qubits used in the quantum circuit. This corresponds to the number of binary variables or elements in the search space.
     */
    GroverSearch(int num_qubits);

    /**
     * @brief Performs the Grover's Search algorithm to find the target element in the database.
     * 
     * This function applies the Grover Search algorithm to a given database and attempts to find the target element.
     * The Grover algorithm amplifies the probability amplitude of the target element through successive applications of the Grover operator.
     * 
     * @param database A binary vector representing the database. The target element is assumed to be marked in the database.
     * @return The index of the target element, or -1 if the target is not found.
     */
    int search(const std::vector<int>& database);

private:
    int num_qubits; ///< The number of qubits used in the quantum circuit (which corresponds to the number of elements in the search space).

    /**
     * @brief The oracle function that marks the target element in the database.
     * 
     * The oracle is a black-box quantum operation that flips the sign of the amplitude of the target element in the quantum superposition.
     * This marks the target element by applying a negative phase shift to it, making it distinguishable from the other elements.
     * 
     * @param database A Boost vector representing the binary database.
     * @param target The target element to search for. This is the element that will be marked by the oracle.
     * @return The index of the target element in the database.
     */
    int oracle(const boost::numeric::ublas::vector<int>& database, int target);

    /**
     * @brief Applies the Grover operator to amplify the amplitude of the target element.
     * 
     * The Grover operator consists of two steps:
     * 1. The **oracle** which marks the target element by flipping its sign.
     * 2. The **diffusion operator** which amplifies the probability of the target element by increasing the amplitude of the marked state.
     * The Grover operator is applied iteratively to increase the probability of finding the target element.
     * 
     * @param state A Boost vector representing the quantum state, which is a superposition of all possible states. The Grover operator acts on this state.
     */
    void applyGroverOperator(boost::numeric::ublas::vector<int>& state);
};

#endif // GROVER_SEARCH_H
