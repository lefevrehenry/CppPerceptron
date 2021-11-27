#ifndef PERCEPTRON_PERCEPTRON_H
#define PERCEPTRON_PERCEPTRON_H

// Perceptron
#include <Perceptron/Function.h>
#include <Perceptron/PerceptronTraits.h>

// Standard Library
#include <array>
#include <numeric>
#include <random>

namespace std
{

// template< std::size_t N, std::activation_function F >
// Perceptron<N,F>& make_perceptron()
// {
//     Perceptron<N,F> p;
//
//     return p;
// }

}

template< std::size_t N, std::activation_function F >
struct Perceptron
{
    // static constexpr std::size_t Size = N;
    // static constexpr std::activation_function Function = F;

public:
    Perceptron() :
        biais(0.f),
        weights({})
    {
        reinit();
    }

public:
    /**
     *
     */
    void reinit()
    {
        std::random_device rd;
        std::uniform_real_distribution<float> uniform(-1.f,1.f);

        auto get_random = [&]() -> float {
            return uniform(rd);
        };

        std::generate(std::begin(weights), std::end(weights), get_random);

        biais = get_random();
    }
    /**
     *
     */
    float compute(const std::array<float,N>& inputs)
    {
        float x = std::inner_product(std::begin(weights), std::end(weights), std::begin(inputs), 0) - biais;
        float y = std::evaluate<F>(x);

        return y;
    }
    /**
     *
     */
    void train(const std::array<float,N>& inputs, float expected_output)
    {
        float output = compute(inputs);

        std::perceptron_traits<N,F>::train(weights, inputs, output, expected_output);
    }

private:
    float biais;
    std::array<float, N> weights;

};

// extern template Perceptron<float, N>;

#endif // PERCEPTRON_PERCEPTRON_H
