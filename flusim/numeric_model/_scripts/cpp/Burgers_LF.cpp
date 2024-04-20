#include<iostream>
#include<vector>
#include<cmath>


std::vector<std::vector<double>> LF_Burgers(std::vector<double> u0, int n, double T, double CFL, double left_bd, double right_bd, int bc)
{
  if (bc == 1){
    return std::vector<std::vector<double>> LF_Burgers_bc1(std::vector<double> u0, int n, double T, double CFL, double left_bd, double right_bd);
  }
  else if (bc == 2){
    std::vector<std::vector<double>> LF_Burgers_bc2(std::vector<double> u0, int n, double T, double CFL, double left_bd, double right_bd);
  }
  else {
    std::vector<std::vector<double>> LF_Burgers_bc3(std::vector<double> u0, int n, double T, double CFL, double left_bd, double right_bd);
  }

}




// function to calculate Burgers equation with boundary condition 1, using LF scheme, needing initial condition u0, average grid numers n in [0,1], end_time T, CFL number CFL
std::vector<std::vector<double>> LF_Burgers_bc1(std::vector<double> u0, int n, double T, double CFL, double left_bd, double right_bd)
{
   // spacial and time steps, time_steps

  double space_length = right_bd - left_bd;
  

  double dx = space_length/n;

  double dt = CFL*dx;

  int time_grid = floor(T/dx);

  // intial the solution

  std::vector<std::vector<double>> u(n+1,std::vector<double>(time_grid,0));

   for (int i = 0;i<n; i++)
   {
     u[i][0] = u0[i];

   }


   
  // begin calculation, with boundary condition needed



  

  


}



// calculate the flux for LF scheme, but it depends on the boundary condition !!!!!!
std::vector<double> LF_flux_Burgers_bc1(std::vector<double> un, double dt)
{

  int un_length = un.size();

  std::vector<double> fn (un_length,0);


  for (int i = 0; i<un_length; i++)
  {

    fn[i] = 0.5 * (un[i+1] * un[i+1] - u[i] * u[i]) - (0.5/dt) * (un[i+1] - un[i]);

    // boundary condition needed to complete flux description

  }
  

}


