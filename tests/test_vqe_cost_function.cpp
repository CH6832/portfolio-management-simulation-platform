#include <gtest/gtest.h>
#include "../src/quantum_algorithms/VQECostFunction.hpp"

TEST(VQECostFunctionTest, EnergyCalculation) {
    std::vector<double> hamiltonian = {1.0, -1.0, 0.5};
    VQECostFunction costFunction(hamiltonian);

    QuantLib::Array params = {2.0, 3.0, 4.0};
    double expectedEnergy = 1.0 * 2.0 + (-1.0) * 3.0 + 0.5 * 4.0;
    ASSERT_NEAR(costFunction.value(params), expectedEnergy, 1e-9);
}

TEST(VQECostFunctionTest, GradientCalculation) {
    std::vector<double> hamiltonian = {1.0, -1.0, 0.5};
    VQECostFunction costFunction(hamiltonian);

    QuantLib::Array params = {2.0, 3.0, 4.0};
    QuantLib::Array grad(hamiltonian.size());
    costFunction.gradient(grad, params);

    for (size_t i = 0; i < hamiltonian.size(); ++i) {
        ASSERT_NEAR(grad[i], hamiltonian[i], 1e-9);
    }
}
