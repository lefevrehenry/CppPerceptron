#ifndef PERCEPTRON_PERCEPTRONTRAITS_H
#define PERCEPTRON_PERCEPTRONTRAITS_H

// Perceptron
#include <Perceptron/Function.h>

// Standard Library
#include <algorithm>
#include <array>
#include <functional>

namespace std
{

// template< std::size_t N, std::activation_function F >
// Perceptron<N,F>& make_perceptron()
// {
//     Perceptron<N,F> p;
//
//     return p;
// }

template< std::size_t N, std::activation_function F >
struct perceptron_traits
{
};

template< std::size_t N >
struct perceptron_traits<N, std::activation_function::heaviside>
{
    /**
     * weight correction when 'heaviside' function is used
     * source: https://ichi.pro/fr/algorithme-d-apprentissage-perceptron-une-explication-graphique-de-son-fonctionnement-235136808040821
     */
    static void train(std::array<float,N>& weights, const std::array<float,N>& inputs, float output, float expected_output)
    {
        using Add = std::plus<float>;
        using Sub = std::minus<float>;

        if(expected_output == 1 && output < 0)
        {
            // weights += inputs
            std::transform(std::begin(weights),std::end(weights),std::begin(inputs),std::begin(weights),Add());
        }
        else if(expected_output == 0 && output >= 0)
        {
            // weights -= inputs
            std::transform(std::begin(weights),std::end(weights),std::begin(inputs),std::begin(weights),Sub());
        }
    }
};

template< std::size_t N >
struct perceptron_traits<N, std::activation_function::sigmoide>
{
    static void train(std::array<float,N>& weights, const std::array<float,N>& inputs, float output, float expected_output)
    {
        throw std::runtime_error("not implemented yet");
    }
};

template< std::size_t N >
struct perceptron_traits<N, std::activation_function::tangente_hyperbolique>
{
    static void train(std::array<float,N>& weights, const std::array<float,N>& inputs, float output, float expected_output)
    {
        throw std::runtime_error("not implemented yet");
    }
};

}

#endif // PERCEPTRON_PERCEPTRON_H
