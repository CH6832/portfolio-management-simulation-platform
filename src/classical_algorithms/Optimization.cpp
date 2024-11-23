#include "Optimization.hpp"
#include <cmath>
#include <random>
#include <iostream>

std::vector<double> Optimization::gradientDescent(
    const std::function<double(const std::vector<double>&)>& costFunction,
    const std::function<std::vector<double>(const std::vector<double>&)>& gradientFunction,
    std::vector<double> initialParams,
    double learningRate,
    int maxIterations
) {
    std::vector<double> params = initialParams;

    for (int i = 0; i < maxIterations; ++i) {
        std::vector<double> gradient = gradientFunction(params);
        for (size_t j = 0; j < params.size(); ++j) {
            params[j] -= learningRate * gradient[j];
        }

        double cost = costFunction(params);
        std::cout << "Iteration " << i + 1 << " | Cost: " << cost << std::endl;

        if (cost < 1e-6) {
            break; // Convergence condition
        }
    }

    return params;
}

std::vector<int> Optimization::simulatedAnnealing(
    const std::function<double(const std::vector<int>&)>& energyFunction,
    std::vector<int> initialState,
    double initialTemperature,
    double coolingRate,
    int maxIterations
) {
    std::vector<int> state = initialState;
    std::vector<int> bestState = state;
    double bestEnergy = energyFunction(state);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dist(0.0, 1.0);

    double temperature = initialTemperature;

    for (int iter = 0; iter < maxIterations; ++iter) {
        std::vector<int> newState = state;

        // Perturb the state (random bit flip)
        int index = gen() % state.size();
        newState[index] = 1 - newState[index];

        double currentEnergy = energyFunction(state);
        double newEnergy = energyFunction(newState);

        if (newEnergy < currentEnergy || dist(gen) < exp((currentEnergy - newEnergy) / temperature)) {
            state = newState;
            if (newEnergy < bestEnergy) {
                bestState = newState;
                bestEnergy = newEnergy;
            }
        }

        temperature *= coolingRate;

        if (temperature < 1e-6) {
            break; // Stop if temperature is too low
        }
    }

    return bestState;
}
