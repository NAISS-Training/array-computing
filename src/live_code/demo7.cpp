#include <iostream>
#include <Eigen/Dense>
#include <print>
#include <vector>
#include "utils_print.h" 

int main()
{
    using Eigen::RowVector3d;
    using Eigen::Vector3d;
    using Eigen::VectorXd;
    using Eigen::MatrixXd;
    using Eigen::seq;
    using Eigen::all;
    using Eigen::last;

    MatrixXd A(10, 10);
    A.setZero();

    A.row(3) << 1, 2, 3, 4, 5, 6, 7, 8, 9, 10;
    A.col(3) << 1, 2, 3, 4, 5, 6, 7, 8, 9, 10;
    A.col(1).setOnes();

    utils::print("A", A);

    MatrixXd B(10, 10);
    B.setZero();

    B(seq(3, 5), seq(3, 5)).setConstant(1);
    B(seq(0, 9, 2), seq(0, 9, 2)).setConstant(2);

    utils::print("B", B);

    B(all, last).setConstant(3);
    B(all, last - 1).setConstant(4);

    utils::print("B", B);

    MatrixXd C(10, 10);
    VectorXd values(100);
    values.setLinSpaced(100, 1, 100);
    C = values.reshaped(10, 10);

    utils::print("C", C);

    std::vector<int> idx = { 1, 3, 4, 6, 7, 9 };

    auto D = C(idx, idx);
    utils::print("D", D);
}