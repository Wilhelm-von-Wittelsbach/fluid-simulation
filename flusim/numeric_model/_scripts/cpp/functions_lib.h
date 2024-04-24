// function library

#ifndef FUNCTIONS_LIB_H
#define FUNCTIONS_LIB_H

double max_elementof_vector(std::vector<double> v);

double minmod(double a, double b);

double Burgers_f(double x);

double Burgers_df(double x);

double Godunov_flux_Burgers(double ul, double ur);

#endif
