#include <iostream>
#include <Eigen/Dense>
#include <print>
#include "utils_print.h" 

int main()
{
    using Eigen::RowVector3d;
    using Eigen::Vector3d;
    using Eigen::Matrix4d;

    RowVector3d r(1.0, 2.0, 3.0);   
    Vector3d s(1.0, 2.0, 3.0); 

    utils::print("r", r);
    utils::print("s", s);

    Matrix4d A;
    Matrix4d B;

    A.setRandom();
    B.setRandom();

    utils::print("A", A);
    utils::print("B", B);

    Matrix4d C = A + B;

    utils::print("A + B", C);

    C = A * 10.0;

    utils::print("A * 10.0", C);

    C = A * B;

    utils::print("A * B", C);

    C = A + Matrix4d::Constant(100.0);

    utils::print("A + Matrix4d::Constant(100.0)", C);

    C = A.array() + 200.0;

    utils::print("A.array() + 200.0", C);

    C = A.cwiseAbs().cwiseSqrt();

    utils::print("A.cwiseAbs().cwiseSqrt()", C);

    C = A.array().abs().sqrt();

    utils::print("A.array().abs().sqrt()", C);
}