#ifndef QAOA_H
#define QAOA_H

#include <vector>

class QAOA {
public:
    QAOA(int p);
    std::vector<double> optimizePortfolioQAOA(const std::vector<double>& returns, const std::vector<std::vector<double>>& covariance);

private:
    int depth;  // Number of layers in QAOA
};

#endif // QAOA_H
