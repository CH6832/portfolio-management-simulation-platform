#ifndef DATALOADER_H
#define DATALOADER_H

#include <vector>
#include <string>

class DataLoader {
public:
    static std::vector<double> loadReturns(const std::string& filename);
    static std::vector<std::vector<double>> loadCovariance(const std::string& filename);
};

#endif // DATALOADER_H
