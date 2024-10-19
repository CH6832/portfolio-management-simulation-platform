#include "GroverSearch.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>

GroverSearch::GroverSearch(int n, const std::vector<int>& marked) : n(n), markedIndices(marked) {
    // Initialize random seed for the simulation
    std::srand(std::time(nullptr));
}

std::vector<int> GroverSearch::run() {
    int iterations = static_cast<int>(std::floor(std::sqrt(static_cast<double>(1 << n)))); // Number of iterations
    std::vector<int> candidates(1 << n); // Initialize the candidate states

    // Initialize candidates with indices 0, 1, ..., 2^n - 1
    for (int i = 0; i < (1 << n); ++i) {
        candidates[i] = i;
    }

    for (int i = 0; i < iterations; ++i) {
        candidates = applyOracle(candidates);
        candidates = applyDiffusionOperator(candidates);
    }

    return candidates;
}

std::vector<int> GroverSearch::applyOracle(const std::vector<int>& candidates) {
    std::vector<int> result = candidates;

    // Flip the sign of the marked states
    for (const auto& index : markedIndices) {
        if (index >= 0 && index < candidates.size()) {
            result[index] *= -1; // Simulating the oracle
        }
    }
    return result;
}

std::vector<int> GroverSearch::applyDiffusionOperator(const std::vector<int>& candidates) {
    std::vector<int> result = candidates;
    double mean = 0.0;

    // Calculate mean
    for (const auto& candidate : candidates) {
        mean += candidate;
    }
    mean /= candidates.size();

    // Apply the diffusion operator
    for (auto& candidate : result) {
        candidate = 2 * mean - candidate;
    }
    return result;
}

void GroverSearch::printResults(const std::vector<int>& results) {
    std::cout << "Possible Solutions:\n";
    for (const auto& result : results) {
        if (result < 0) {
            std::cout << "Found marked index: " << -result << std::endl;
        }
    }
}
