#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include "functions_lib.h"




// calculate the flux for LF scheme of dimension 1
// Here the boundaru condition is 1, which is periodic 
std::vector<double> LF_flux_Burgers_dim1_bc1(std::vector<double> un, double lamda_n)
{

  

  int un_length = un.size();

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




// function to calculate Burgers equation with boundary condition 1, using LF scheme, needing initial condition u0, average grid numers n in [0,1], end_time T, CFL number CFL
std::vector<std::vector<double>> LF_Burgers_dim1(std::vector<double> u0, int N, double T, double CFL, double left_bd, double right_bd)
{
   // length

  double space_length = right_bd - left_bd;

  //current time. begins from 0
  
  double current_t = 0;

  // time step

  double dt = 0;

  // lamda = time step / space step

  double lamda = 1;

  // time evolution steps

  int tik = 0;

  // space step

  double dx = space_length/N;

  //flux

  std::vector<double> f_half(N+1,0);

  std::vector<double> newtime_row(N,0);


  // Here we need max_wave_velocity * time_step/space_step <=CFL number

  // intial the solution, here first component is time grid, second is space grid

  std::vector<std::vector<double>> u(1,std::vector<double>(N,0));

   for (int i = 0;i<N; i++)
   {
     u[0][i] = u0[i];
   }


  // begin calculation, evolute until time achieves maximum time

     while (current_t<=T)
     {

      // notice here max_was_velocity us f^{/prime}, for Burgers equation it's u

      double max_un = max_elementof_vector(u[tik]);

      // calculate dt from CFL

       dt = CFD*dx/(max_un);

       // if dt larger than the remain time, then dt should be the remain time

       if (dt>T- current_t)
       {
        dt = T - current_t;
        }
       
 
      // add new row for u


       u.push_back(newtime_row);

       lamda = dt/dx;

       // calculate flux

       f_half = LF_flux_Burgers_dim1_bc1(u[tik], lamda);

       //calculate u for next time

       for (int j= 0; j<N;j++)
       {
        u[tik + 1][j] = u[tik][j] - lamda*(f_half[j+1]-f_half[j]);
       }
           
      // update time

       current_t = current_t + dt;

       tik = tik + 1;

     }


return u;
  

}






