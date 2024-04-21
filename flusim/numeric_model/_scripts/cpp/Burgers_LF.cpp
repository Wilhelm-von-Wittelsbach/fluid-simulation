#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include "functions_lib.h"







//std::vector<std::vector<double>> LF_Burgers(std::vector<double> u0, int n, double T, double CFL, double left_bd, double right_bd, int bc)
//{
  //if (bc == 1){
 //   return std::vector<std::vector<double>> LF_Burgers_bc1(std::vector<double> u0, int n, double T, double CFL, double left_bd, double right_bd);
 // }
  //else if (bc == 2){
  //  std::vector<std::vector<double>> LF_Burgers_bc2(std::vector<double> u0, int n, double T, double CFL, double left_bd, double right_bd);
  //}
  //else {
  //  std::vector<std::vector<double>> LF_Burgers_bc3(std::vector<double> u0, int n, double T, double CFL, double left_bd, double right_bd);
 // }

//}




// function to calculate Burgers equation with boundary condition 1, using LF scheme, needing initial condition u0, average grid numers n in [0,1], end_time T, CFL number CFL
std::vector<std::vector<double>> LF_Burgers_bc1(std::vector<double> u0, int N, double T, double CFL, double left_bd, double right_bd)
{
   // spacial and time steps, time_steps

  double space_length = right_bd - left_bd;
  
  double current_t = 0;

  double dt = 0;

  int tik = 0;

  double dx = space_length/N;

  // Here we need max_wave_velocity * time_step/space_step <=CFL number

 

  // intial the solution, here first component is time grid, second is space grid

  std::vector<std::vector<double>> u(1,std::vector<double>(N,0));

   for (int i = 0;i<N; i++)
   {
     u[0][i] = u0[i];
   }


  // begin calculation, with boundary condition needed

     while (current_t<=T)
     {

      // notice here max_was_velocity us f^{/prime}, for Burgers equation it's u

      double max_un = max_elementof_vector(u[tik]);

       dt = 0.95*dx/(max_un);

       std::vector<double> newtime_row(N,0);

       u.push_back(newtime_row);

     }


return u;
  

  


}



// calculate the flux for LF scheme, but it depends on the boundary condition !!!!!!
// Here the boundaru condition is 1, which is periodic 
std::vector<double> LF_flux_Burgers_bc1(std::vector<double> un, double dt, double dx)
{

  

  int un_length = un.size();

  double lamda_n = dt/dx;

  std::vector<double> fn(un_length+1,0);

  // fn[0] = fn_(0-1/2)

  fn[0] = 0.5 * (0.5*un[0] * un[0] - 0.5*un[un_length-1] * un[un_length-1]) - (0.5/lamda_n) * (un[0] - un[un_length-1]);

  // fn[un_length] = fn_N-1+1/2

  fn[un_length] = 0.5 * (0.5*un[0] * un[0] - 0.5*un[un_length-1] * un[un_length-1]) - (0.5/lamda_n) * (un[0] - un[un_length-1]);
  
   //

  for (int i = 1; i<un_length-1; i++)
  {
    fn[i] = 0.5 * (0.5*un[i] * un[i] - 0.5*un[i-1] * un[i-1]) - (0.5/lamda_n) * (un[i] - un[i-1]);
  }
  
  return fn;

}






