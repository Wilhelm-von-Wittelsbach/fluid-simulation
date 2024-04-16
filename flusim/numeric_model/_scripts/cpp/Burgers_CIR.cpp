#include<iostream>
#include<vector>
#include<cmath>

// function to calculate Burgers equation using LF scheme, needing initial condition u0, average grid numers n in [0,1], end_time T, CFL number CFL
std::vector<std::vector<double>> LF_for_Burgers(std::vector<double> u0, int n, double T, double CFL)
{
   // spacial and time steps, time_steps
  double dx = 1.0/n;

  double dt = CFL*dx;

  int time_grid = floor(T/dx);

  // intial the solution

  std::vector<std::vector<double>> u(n+1,std::vector<double>(time_grid,0));

   for (int i = 0;i<n; i++)
   {
     u[i][0] = u0[i];

   }
   
  // begin calculation

  

  


}


