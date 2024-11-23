#ifndef VQECOSTFUNCTION_HPP
#define VQECOSTFUNCTION_HPP

#include <ql/math/optimization/costfunction.hpp>
#include <ql/math/array.hpp>
#include <vector>

/**
 * @class VQECostFunction
 * @brief A class that implements the cost function for the Variational Quantum Eigensolver (VQE).
 * 
 * This class is responsible for defining the cost function used in the VQE algorithm,
 * which computes the energy of a quantum system described by a Hamiltonian.
 * The VQE cost function is based on the principle of minimizing the energy expectation value
 * of a quantum state, given a set of parameters (which typically describe the quantum state).
 * The class derives from QuantLib's `CostFunction` to integrate with optimization routines.
 */
class VQECostFunction : public QuantLib::CostFunction {
public:
    /**
     * @brief Constructor for the VQECostFunction class.
     * 
     * Initializes the cost function with the Hamiltonian values that represent the quantum system.
     * 
     * @param hamiltonian A vector of doubles representing the Hamiltonian of the quantum system.
     * This Hamiltonian is used to calculate the energy expectation values.
     */
    VQECostFunction(const std::vector<double>& hamiltonian) : hamiltonian_(hamiltonian) {}

    /**
     * @brief Computes the value of the cost function (energy) for a given set of parameters.
     * 
     * This function calculates the energy of the quantum system by performing a weighted sum of the
     * Hamiltonian elements and the given parameters. The result represents the energy expectation value
     * of the quantum state described by the parameters.
     * 
     * @param params An array of parameters that define the quantum state (usually angles in VQE).
     * @return The computed energy value.
     */
    QuantLib::Real value(const QuantLib::Array& params) const override {
        double energy = 0.0;

        // Loop over the Hamiltonian and compute the weighted sum with the parameters
        for (size_t i = 0; i < hamiltonian_.size(); ++i) {
            energy += hamiltonian_[i] * params[i];  // Simple dot product between Hamiltonian and params
        }

        // Return the total energy
        return energy;
    }

    /**
     * @brief Computes the gradient of the cost function with respect to the parameters.
     * 
     * The gradient represents how the energy changes with respect to each parameter. It is used by
     * optimization algorithms to guide the search for the minimum energy configuration.
     * 
     * @param grad An array that will store the computed gradient values.
     * @param params An array of parameters to compute the gradient at the given point.
     */
    void gradient(QuantLib::Array& grad, const QuantLib::Array& params) const override {
        // The gradient is simply the Hamiltonian values (since it is linear with respect to params)
        for (size_t i = 0; i < hamiltonian_.size(); ++i) {
            grad[i] = hamiltonian_[i];  // Gradient is constant, equal to the Hamiltonian elements
        }
    }

    /**
     * @brief Computes both the value of the cost function and its gradient simultaneously.
     * 
     * This function is an optimization convenience, allowing both the value (energy) and gradient to
     * be computed in a single step, which can improve optimization efficiency.
     * 
     * @param grad An array to store the computed gradient values.
     * @param params An array of parameters to compute both the value and gradient at the given point.
     * @return The computed energy value (cost function value).
     */
    QuantLib::Real valueAndGradient(QuantLib::Array& grad, const QuantLib::Array& params) const override {
        // First compute the gradient
        gradient(grad, params);

        // Then compute and return the value of the cost function
        return value(params);  // Return the energy (value of the cost function)
    }

private:
    const std::vector<double>& hamiltonian_;  ///< Reference to the Hamiltonian values for the quantum system
};

#endif // VQECOSTFUNCTION_HPP
