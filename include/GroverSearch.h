#ifndef GROVERSEARCH_H
#define GROVERSEARCH_H

#include <vector>

class GroverSearch {
public:
    GroverSearch(int n, const std::vector<int>& marked);
    std::vector<int> run();
    void printResults(const std::vector<int>& results);

private:
    int n; // Number of bits
    std::vector<int> markedIndices; // Indices of marked states
    std::vector<int> applyOracle(const std::vector<int>& candidates);
    std::vector<int> applyDiffusionOperator(const std::vector<int>& candidates);
};

#endif // GROVERSEARCH_H
