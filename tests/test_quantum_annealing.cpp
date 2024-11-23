#include <gtest/gtest.h>
#include <boost/numeric/ublas/matrix.hpp>
#include "../src/quantum_algorithms/QuantumAnnealing.hpp"

TEST(QuantumAnnealingTest, SolveQUBO) {
    int num_qubits = 4;
    QuantumAnnealing annealer(num_qubits);

    // Create a simple QUBO matrix
    boost::numeric::ublas::matrix<double> QUBO_matrix(num_qubits, num_qubits);
    for (int i = 0; i < num_qubits; ++i) {
        for (int j = 0; j < num_qubits; ++j) {
            QUBO_matrix(i, j) = (i == j) ? -1.0 : 0.5;
        }
    }

    std::vector<int> result = annealer.solveQUBO(QUBO_matrix);

    // Validate the result (example condition)
    ASSERT_EQ(result.size(), num_qubits);
    for (int bit : result) {
        ASSERT_TRUE(bit == 0 || bit == 1);
    }
}
