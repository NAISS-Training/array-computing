#include <iostream>
#include <Eigen/Dense>
#include <print>
#include "utils_print.h" 

int main()
{
    Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> F;
    F.resize(3, 3);

    F.setRandom();

    utils::print("F", F);
    std::println("Raw data of F {:p}", static_cast<const void*>(F.data()));

    Eigen::MatrixXd G(3, 3);
    G.setRandom();

    utils::print("G", G);
    std::println("Raw data of G {:p}", static_cast<const void*>(G.data()));

    F.resize(1, 9);

    utils::print("F_resized", F);
    std::println("Raw data of F {:p}", static_cast<const void*>(F.data()));

    G.resize(6, 6);
    utils::print("G_resized", G);
    std::println("Raw data of G {:p}", static_cast<const void*>(G.data()));
   
}