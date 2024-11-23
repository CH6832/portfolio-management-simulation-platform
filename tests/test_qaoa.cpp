#include <gtest/gtest.h>
#include "../src/quantum_algorithms/QAOA.hpp"

TEST(QAOATest, OptimizationResult) {
    int num_qubits = 4;
    int steps = 3;
    std::vector<double> gamma = {0.1, 0.2, 0.3};
    std::vector<double> beta = {0.5, 0.6, 0.7};
    std::vector<double> problem_instance = {0.1, 0.3, 0.7, 0.5};

    QAOA qaoa(num_qubits, steps);
    qaoa.setParameters(gamma, beta);

    double result = qaoa.optimize(problem_instance);

    // Validate the optimization result (example condition)
    ASSERT_TRUE(result >= 0.0);
}
