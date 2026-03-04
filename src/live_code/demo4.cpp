#include <iostream>
#include <Eigen/Dense>
#include <print>
#include "utils_print.h" 

int main()
{
    using Eigen::RowVector3d;
    using Eigen::Vector3d;
    using Eigen::Matrix4d;

    Vector3d s{0.0, 0.0, 1.0};
    Vector3d t{0.0, 1.0, 0.0};

    auto dot_product = s.dot(t);

    std::println("Dot product = {}", dot_product);

    auto u = s.cross(t);

    utils::print("u", u);

    u = t.cross(s);

    utils::print("u", u);
}