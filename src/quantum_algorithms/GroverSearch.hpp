#pragma once

#ifndef GROVER_SEARCH_H
#define GROVER_SEARCH_H

#include <vector>
#include <boost/numeric/ublas/vector.hpp>  // Boost for vector operations

class GroverSearch {
public:
    GroverSearch(int num_qubits);
    int search(const std::vector<int>& database);

private:
    int num_qubits;
    int oracle(const boost::numeric::ublas::vector<int>& database, int target);
    void applyGroverOperator(boost::numeric::ublas::vector<int>& state);
};

#endif // GROVER_SEARCH_H
