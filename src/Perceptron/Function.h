#ifndef PERCEPTRON_FUNCTION_H
#define PERCEPTRON_FUNCTION_H

// Standard Library
#include <string>
#include <stdexcept>

namespace std
{
    enum class activation_function
    {
        heaviside,
        sigmoide,
        tangente_hyperbolique
    };

    template<activation_function Func>
    std::string function_name();

    struct activate_function_not_found : public std::runtime_error
    {
        activate_function_not_found(const std::string& what_arg) : runtime_error(what_arg) { }
    };

    template<activation_function Func>
    float evaluate(float x) { throw std::activate_function_not_found("'std::evaluate' not implemented for template '" + std::function_name<Func>() + "'"); }

    template<activation_function Func>
    float derivate(float x) { throw std::activate_function_not_found("'std::derivate' not implemented for template '" + std::function_name<Func>() + "'"); }
};

#endif // PERCEPTRON_FUNCTION_H
