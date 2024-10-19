#include "DataLoader.h"
#include <fstream>
#include <sstream>
#include <iostream>

std::vector<double> DataLoader::loadReturns(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<double> returns;
    std::string line;

    while (std::getline(file, line)) {
        returns.push_back(std::stod(line));
    }
    return returns;
}

std::vector<std::vector<double>> DataLoader::loadCovariance(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<std::vector<double>> covariance;
    std::string line;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::vector<double> row;
        double value;

        while (iss >> value) {
            row.push_back(value);
        }
        covariance.push_back(row);
    }
    return covariance;
}
