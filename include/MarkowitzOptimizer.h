#ifndef MARKOWITZOPTIMIZER_H
#define MARKOWITZOPTIMIZER_H

#include <vector>

class MarkowitzOptimizer {
public:
    MarkowitzOptimizer(const std::vector<double>& returns, const std::vector<std::vector<double>>& covariance);
    std::vector<double> optimizePortfolio(double riskAversion);

private:
    std::vector<double> expectedReturns;
    std::vector<std::vector<double>> covarianceMatrix;
};

#endif // MARKOWITZOPTIMIZER_H
