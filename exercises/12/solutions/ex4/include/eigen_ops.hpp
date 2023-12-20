#ifndef EIGEN_OPS_HPP__
#define EIGEN_OPS_HPP__

#include <Eigen/Dense>

Eigen::MatrixXd matrix_multiply(const Eigen::MatrixXd& m1, const Eigen::MatrixXd& m2);
Eigen::MatrixXd matrix_invert(const Eigen::MatrixXd& m);

#endif /* EIGEN_OPS_HPP__ */
