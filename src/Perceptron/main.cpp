#include <iostream>

// Perceptron
#include <Perceptron/Function.h>
#include <Perceptron/Perceptron.h>

int main(int argc, char* argv[])
{
    Perceptron<3, std::activation_function::heaviside> p;
    p.compute({1.f,0.f,0.f});
    p.train({1.f,0.f,0.f}, 1.f);

    for (int i = -5; i <= 5; ++i) {
        float x = i / 10.f;
        float y = std::evaluate<std::activation_function::heaviside>(x);
        std::cout << "f(" << x << ") = " << y << std::endl;
    }

    return 0;
}
