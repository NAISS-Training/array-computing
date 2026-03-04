#include <iostream>
#include <Eigen/Dense>
#include <print>
#include "utils_print.h" 

int main()
{
    using Eigen::RowVector3d;
    using Eigen::Vector3d;
    using Eigen::VectorXd;
    using Eigen::Matrix4d;


    Matrix4d A;
    VectorXd values(A.size());
    values.setLinSpaced(A.size(), 1, 16);
    A = values.reshaped(4, 4).transpose();

    utils::print("A", A);
    std::println("Raw data of A {:p}", static_cast<const void*>(A.data()));

    auto B = A.reshaped(16, 1);

    utils::print("B", B);
    std::println("Raw data of B {:p}", static_cast<const void*>(B.data()));

}