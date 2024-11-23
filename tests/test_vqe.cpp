#include <gtest/gtest.h>
#include "../src/quantum_algorithms/VQE.hpp"

TEST(VQETest, GroundStateEnergyCalculation) {
    int num_qubits = 4;
    std::vector<double> hamiltonian = {1.0, -1.0, 0.5, 0.2};
    std::vector<double> initial_params = {0.1, 0.2, 0.3, 0.4};

    VQE vqe(num_qubits, hamiltonian);
    double groundStateEnergy = vqe.computeGroundStateEnergy(hamiltonian, initial_params);

    // Add appropriate assertions based on known expected results for the input.
    ASSERT_TRUE(groundStateEnergy < 1.0); // Example condition.
}
