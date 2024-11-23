#include <ql/math/optimization/costfunction.hpp>
#include <ql/math/array.hpp>
#include <vector>

class VQECostFunction : public QuantLib::CostFunction {
public:
    VQECostFunction(const std::vector<double>& hamiltonian) : hamiltonian_(hamiltonian) {}

    // Calculate the value of the cost function
    QuantLib::Real value(const QuantLib::Array& params) const override {
        double energy = 0.0;
        for (size_t i = 0; i < hamiltonian_.size(); ++i) {
            energy += hamiltonian_[i] * params[i]; // Simplified energy calculation
        }
        return energy;
    }

    // (Optional) Calculate the gradient of the cost function
    void gradient(QuantLib::Array& grad, const QuantLib::Array& params) const override {
        for (size_t i = 0; i < hamiltonian_.size(); ++i) {
            grad[i] = hamiltonian_[i]; // Simplified gradient calculation
        }
    }

    // Provide the size of the problem
    QuantLib::Real valueAndGradient(QuantLib::Array& grad, const QuantLib::Array& params) const override {
        gradient(grad, params);
        return value(params);
    }

private:
    const std::vector<double>& hamiltonian_;
};
