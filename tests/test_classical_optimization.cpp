#include <gtest/gtest.h>
#include "../src/classical_algorithms/Optimization.hpp"

TEST(ClassicalOptimizationTest, GradientDescentConvergence) {
    // Define a simple quadratic cost function: f(x) = (x1^2 + x2^2)
    auto costFunction = [](const std::vector<double>& params) -> double {
        return params[0] * params[0] + params[1] * params[1];
    };

    // Define its gradient: grad(f) = [2x1, 2x2]
    auto gradientFunction = [](const std::vector<double>& params) -> std::vector<double> {
        return {2.0 * params[0], 2.0 * params[1]};
    };

    std::vector<double> initialParams = {3.0, 4.0};
    double learningRate = 0.1;
    int maxIterations = 100;

    std::vector<double> optimizedParams = Optimization::gradientDescent(
        costFunction, gradientFunction, initialParams, learningRate, maxIterations
    );

    ASSERT_NEAR(optimizedParams[0], 0.0, 1e-6);
    ASSERT_NEAR(optimizedParams[1], 0.0, 1e-6);
}

TEST(ClassicalOptimizationTest, SimulatedAnnealingOptimization) {
    // Define a simple energy function: H(x) = sum(x)
    auto energyFunction = [](const std::vector<int>& state) -> double {
        double energy = 0.0;
        for (int bit : state) {
            energy += bit;
        }
        return energy;
    };

    std::vector<int> initialState = {0, 1, 0, 1};
    double initialTemperature = 10.0;
    double coolingRate = 0.9;
    int maxIterations = 100;

    std::vector<int> result = Optimization::simulatedAnnealing(
        energyFunction, initialState, initialTemperature, coolingRate, maxIterations
    );

    // Expect the result to be the lowest-energy state [0, 0, 0, 0]
    for (int bit : result) {
        ASSERT_EQ(bit, 0);
    }
}
