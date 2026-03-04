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
    MatrixXd B(100, 100);
    B.setRandom();

    FullPivLU<MatrixXd> lu(A);

    MatrixXd X = lu.solve(B);

    utils::print("Solution X", X(seq(0, 10), seq(0, 10)));

}