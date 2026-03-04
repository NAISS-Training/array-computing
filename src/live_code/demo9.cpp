#include <iostream>
#include <Eigen/Dense>
#include <print>
#include <vector>
#include "utils_print.h" 

int main()
{
    using namespace Eigen;

    MatrixXd A(100, 100);
    A.setRandom();
    VectorXd b(100);
    b.setRandom();

    VectorXd x = A.colPivHouseholderQr().solve(b);

    double error = (A * x - b).norm();
    utils::print("Solution x", x);
    std::println("Error ||Ax - b|| = {}", error);
}