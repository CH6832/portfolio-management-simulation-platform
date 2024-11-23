#include <gtest/gtest.h>
#include "../src/quantum_algorithms/GroverSearch.hpp"

TEST(GroverSearchTest, SearchTarget) {
    int num_qubits = 3;
    std::vector<int> database = {0, 0, 1, 0, 0}; // Target = 1

    GroverSearch grover(num_qubits);
    int targetIndex = grover.search(database);

    // Validate the search result
    ASSERT_EQ(targetIndex, 2);
}

TEST(GroverSearchTest, TargetNotFound) {
    int num_qubits = 3;
    std::vector<int> database = {0, 0, 0, 0, 0}; // No target

    GroverSearch grover(num_qubits);
    int targetIndex = grover.search(database);

    // Validate that no target is found
    ASSERT_EQ(targetIndex, -1);
}
