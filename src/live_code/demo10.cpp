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

    std::vector<VectorXd> b;
    std::vector<VectorXd> x;

    for (int i = 0; i < 10; ++i) 
    {
        VectorXd bi(100);
        bi.setRandom();
        b.push_back(bi);

        VectorXd xi(100);
        x.push_back(xi);
    }

    FullPivLU<MatrixXd> lu(A);

    for (auto i = 0; auto& xi : x)
    {
        xi = lu.solve(b[i++]);
        double error = (A * xi - b[i-1]).norm();
        utils::print("Solution x", xi(seq(0, 10)));
        std::println("Error ||Ax - b|| = {}", error);
    }

}