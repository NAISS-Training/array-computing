#include <iostream>
#include <Eigen/Dense>
#include <print>
#include "utils_print.h" 

int main()
{
    Eigen::Matrix<double, 3, 3> A;
    Eigen::Matrix3d B;

    A.setZero();
    B.setOnes();

    utils::print("A", A);
    utils::print("B", B);

    Eigen::Vector<double, 3> v;
    Eigen::Vector3d w;

    v = Eigen::Vector3d::Zero();
    w.setZero();

    utils::print("v", v);
    utils::print("w", w);

    Eigen::Matrix3d D;

    D << 1, 2, 3,
         4, 5, 6,
         7, 8, 9;

    /*
    D.col(0) << 1, 2, 3;
    D.col(1) << 4, 5, 6;
    D.col(2) << 7, 8, 9;
    */

    /*
    D.row(0) << 1, 2, 3;
    D.row(1) << 4, 5, 6;
    D.row(2) << 7, 8, 9;
    */


    utils::print("D", D);

    Eigen::Vector3d vv(1, 2, 3);
    Eigen::Vector3d uu{1, 2, 3};
    Eigen::Vector3d xx;
    xx << 1, 2, 3;

    vv.setLinSpaced(3, 1, 2);
    uu.setRandom();

    utils::print("vv", vv);
    utils::print("uu", uu);

}