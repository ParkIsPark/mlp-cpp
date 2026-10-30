#include <Eigen/Dense>
#include <iostream>

int main()
{
    Eigen::Matrix2d left;
    left << 1.0, 2.0,
            3.0, 4.0;

    Eigen::Matrix2d right;
    right << 5.0, 6.0,
             7.0, 8.0;

    Eigen::Matrix2d expected;
    expected << 19.0, 22.0,
                43.0, 50.0;

    const Eigen::Matrix2d result = left * right;
    if (!result.isApprox(expected)) {
        std::cerr << "Matrix multiplication check failed.\n";
        return 1;
    }

    std::cout << "Eigen " << EIGEN_VERSION_STRING << '\n'
              << "Matrix multiplication:\n" << result << '\n'
              << "C++20 / Eigen setup OK.\n";
    return 0;
}
