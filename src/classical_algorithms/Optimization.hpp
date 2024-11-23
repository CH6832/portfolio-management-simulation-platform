#pragma once

#ifndef CLASSICAL_OPTIMIZATION_HPP
#define CLASSICAL_OPTIMIZATION_HPP

#include <vector>
#include <functional>

class Optimization {
public:
    // Gradient Descent algorithm for a given cost function
    static std::vector<double> gradientDescent(
        const std::function<double(const std::vector<double>&)>& costFunction,
        const std::function<std::vector<double>(const std::vector<double>&)>& gradientFunction,
        std::vector<double> initialParams,
        double learningRate,
        int maxIterations
    );

    // Simulated Annealing (for optimization problems)
    static std::vector<int> simulatedAnnealing(
        const std::function<double(const std::vector<int>&)>& energyFunction,
        std::vector<int> initialState,
        double initialTemperature,
        double coolingRate,
        int maxIterations
    );
};

#endif // CLASSICAL_OPTIMIZATION_HPP
