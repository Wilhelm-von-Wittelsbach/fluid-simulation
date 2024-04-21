//numerical schemes


#ifndef NUMERICAL_SCHEMES_H
#define NUMERICAL_SCHEMES_H


std::vector<std::vector<double>> LF_Burgers_dim1(std::vector<double> u0, int N, double T, double CFL, double left_bd, double right_bd);

std::vector<std::vector<double>> MUSCL_Burgers_dim1_bc1(std::vector<double> u0, int N, double T, double CFL, double left_bd, double right_bd);

std::vector<std::vector<double>> WENO_Burgers_dim1_bc1(std::vector<double> u0, int N, double T, double CFL, double left_bd, double right_bd);

#endif