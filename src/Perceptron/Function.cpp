#include "Function.h"

// Standard Library
#include <cmath>
#include <limits>

// namespace std
// {

template<>
std::string std::function_name<std::activation_function::heaviside>()
{
    return "heaviside";
}

template<>
std::string std::function_name<std::activation_function::sigmoide>()
{
    return "sigmoide";
}

template<>
std::string std::function_name<std::activation_function::tangente_hyperbolique>()
{
    return "tangente_hyperbolique";
}

template<>
float std::evaluate<std::activation_function::heaviside>(float x)
{
    return (x < 0 ? 0.f : 1.f);
}

template<>
float std::derivate<std::activation_function::heaviside>(float x)
{
    return (x != 0 ? 0.f : std::numeric_limits<float>::quiet_NaN());
}

template<>
float std::evaluate<std::activation_function::sigmoide>(float x)
{
    return 1.f / (1.f + std::exp(-x));
}

template<>
float std::derivate<std::activation_function::sigmoide>(float x)
{
    float sig_x = std::evaluate<std::activation_function::sigmoide>(x);
    return sig_x * (1.f - sig_x);
}

template<>
float std::evaluate<std::activation_function::tangente_hyperbolique>(float x)
{
    return std::tanh(x);
}

template<>
float std::derivate<std::activation_function::tangente_hyperbolique>(float x)
{
    float tanh_x = std::evaluate<std::activation_function::tangente_hyperbolique>(x);
    return (1.f - std::pow(tanh_x,2));
}

// }
