#include <iostream>
#include <print>

#include <omp.h>
#include <Eigen/Dense>

#include "utils_print.h"

int main()
{
    const int n = 5000;

    Eigen::MatrixXd A(n, n);
    Eigen::MatrixXd B(n, n);

    A = Eigen::MatrixXd::Random(n, n);
    B = Eigen::MatrixXd::Random(n, n);

    Eigen::MatrixXd C(n, n);

    //int threads[] = { 1, 2, 4, 8, 12, 24, 48 };
    int threads[] = { 1, 2, 3, 4, 5, 6 };

    for (int i = 0; i < 5; i++)
    {
        auto n_threads = threads[i];
        omp_set_num_threads(n_threads);

        double start = omp_get_wtime();
        C = A * B;
        double end = omp_get_wtime();

        std::print("{};{}\n", n_threads, end - start);
    }

    return 0;
}