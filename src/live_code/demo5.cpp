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


    Matrix4d K;
    VectorXd values(K.size());

    values.setLinSpaced(K.size(), 1, 16);

    K = values.reshaped(4,4);

    utils::print("K", K);
    std::println("K.sum() = {}", K.sum());
    std::println("K.prod() = {}", K.prod());
    std::println("K.mean() = {}", K.mean());
    std::println("K.norm() = {}", K.norm());
    std::println("K.maxCoeff() = {}", K.maxCoeff());
    std::println("K.minCoeff() = {}", K.minCoeff());
    std::println("K.trace() = {}", K.trace());
    utils::print("K.diagonal()", K.diagonal());
    std::println("K.determinant() = {}", K.determinant());
}