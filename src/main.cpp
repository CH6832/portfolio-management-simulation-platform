#include <iostream>
#include "../include/MarkowitzOptimizer.h"
#include "../include/DataLoader.h"

int main() {
    std::string returnsFile = "data/returns.csv";  // Load your returns data
    std::string covFile = "data/covariance.csv";   // Load your covariance matrix

    auto returns = DataLoader::loadReturns(returnsFile);
    auto covariance = DataLoader::loadCovariance(covFile);

    MarkowitzOptimizer optimizer(returns, covariance);
    double riskAversion = 2.0; // Example risk aversion parameter
    std::vector<double> optimalWeights = optimizer.optimizePortfolio(riskAversion);

    std::cout << "Optimal Portfolio Weights:\n";
    for (double weight : optimalWeights) {
        std::cout << weight << " ";
    }
    std::cout << std::endl;

    return 0;
}
