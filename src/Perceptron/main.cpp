#include "term_utility.h"

// Perceptron
#include <Perceptron/Function.h>
#include <Perceptron/Perceptron.h>

// Standard Library
#include <iomanip>
#include <iostream>
#include <random>

int main(int argc, char* argv[])
{
    constexpr std::size_t N = 2;
    constexpr std::activation_function F = std::activation_function::heaviside;

    using Perceptron = Perceptron<N,F>;

    Perceptron per;
    // p.compute({1.f,0.f,0.f});
    // p.train({1.f,0.f,0.f}, 1.f);

    std::random_device rd;
    std::uniform_real_distribution<float> uniform(-1.f,1.f);

    auto get = [&]() -> float {
        return uniform(rd);
    };

    // generate a random equation of form: ax + by = d
    float a = get();
    float b = get();
    float d = get();

    // a 2d point with the class it belongs to
    struct Point {
        float x;
        float y;
        bool _class;
    };

    // generate datas
    std::array<Point,100> points;

    auto generate_point = [&a,&b,&d,&get]() -> Point {
        Point p;
        p.x = 5 * get();
        p.y = 5 * get();
        p._class = ((a * p.x) + (b * p.y) >= d);
        return p;
    };
    std::generate(std::begin(points), std::end(points), generate_point);

    std::cout << "==================================" << std::endl;
    std::cout << a << " * X + " << b << " * Y = " << d << std::endl;
    std::cout << "--------------------------" << std::endl;
    for (Point& p : points) {
        bool prediction = per.compute({p.x,p.y});
        std::string color = (prediction == p._class ? std::green() : std::red());
        std::cout << "(" << std::setw(10) << p.x << "," << std::setw(10) << p.y << ") -> " << p._class << " | " << color << "(" << prediction << ")" << std::white() << std::endl;
    }

    std::cout << "--------------------------" << std::endl;
    std::cout << "traning !" << std::endl;
    for (Point& p : points) {
        per.train({p.x,p.y}, p._class);
    }
    for (Point& p : points) {
        per.train({p.x,p.y}, p._class);
    }
    for (Point& p : points) {
        per.train({p.x,p.y}, p._class);
    }


    std::cout << "--------------------------" << std::endl;
    std::cout << "here are the weights found by the perceptron:" << std::endl;
    std::cout << per.weights[0] << " * X + " << per.weights[1] << " * Y = " << per.biais << std::endl;
    std::cout << "--------------------------" << std::endl;
    for (Point& p : points) {
        bool prediction = per.compute({p.x,p.y});
        std::string color = (prediction == p._class ? std::green() : std::red());
        std::cout << "(" << std::setw(10) << p.x << "," << std::setw(10) << p.y << ") -> " << p._class << " | " << color << "(" << prediction << ")" << std::white() << std::endl;
    }
    std::cout << "==================================" << std::endl;

    // for (int i = -5; i <= 5; ++i) {
    //     float x = i / 10.f;
    //     float y = std::evaluate<std::activation_function::heaviside>(x);
    //     std::cout << "f(" << x << ") = " << y << std::endl;
    // }

    return 0;
}
