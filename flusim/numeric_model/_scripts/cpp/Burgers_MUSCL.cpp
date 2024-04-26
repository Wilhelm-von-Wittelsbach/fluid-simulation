#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include "functions_lib.h"





// slope restrictor of periodic boundary bc, second order reconstruction, error estimate: spacial and time second order, but TVD and stable, notice initial condition might cause shock

std::vector<double> slope_res(std::vector<double> un)
{

    int len = un.size();

    std::vector<double> sn(len+2,0);

    // totall from -2 -> n+1. n+4 length,  s0, s1, sn, sn+1 should be treated separatly

    // s0

    if (sign(diff_1_minus_2(un[0],un[len-1])) <> sign(diff_1_minus_2(un[len-1] - un[len-2])))
        {
             sn[0] = 0;
             sn[n] = 0;
        }
        else 
        {
            sn[0] = minmod(diff_1_minus_2(un[0],un[len-1]),diff_1_minus_2(un[len-1] - un[len-2]));
            sn[n] = minmod(diff_1_minus_2(un[0],un[len-1]), diff_1_minus_2(un[len-1] - un[len-2]));
        }

    

    if (sign(diff_1_minus_2(un[1],un[0])) <> sign(diff_1_minus_2(un[0] - un[len-1])))
        {
             sn[1] = 0;
             sn[n+1] = 0;
        }
        else 
        {
            sn[1] = minmod(diff_1_minus_2(un[1],un[0]), diff_1_minus_2(un[0] - un[len-1]));
            sn[n+1] = minmod(diff_1_minus_2(un[1],un[0]), diff_1_minus_2(un[0] - un[len-1]));
        }

    

    // normal cases, no boundary condition considered
    for (int i = 1; i< n-2;i++)
    {
        if (sign(diff_1_minus_2(un[i+1],un[i])) <> sign(diff_1_minus_2(un[i] - un[i-1])))
        {
             sn[i+1] = 0;
        }
        else 
        {
            sn[i+1] = minmod(diff_1_minus_2(un[i+1],un[i]), diff_1_minus_2(un[i] - un[i-1]));
        }
    }

    return sn;


}


std::vector<double> L_U(std::vector<double> un, double dx, std::vector<double> slope)
{


    int len = un.size();

    std::vector<double> L(len,0);

    for (int i = 0;i<len)


}






std::vector<std::vector<double>> MUSCL_Burgers_dim1_bc1(std::vector<double> u0, int N, double T, double CFL, double left_bd, double right_bd)
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

  std::vector<std::vector<double>> u(1, std::vector<double>(N,1));

  std::vector<double>u_star(N,1);

  std::vector<double> newtime_row(N,0);


  double L = 0;

  for (int i=0; i<N;i++)
  {
    u[0][i] = u0[i];
  }


  while (current_t<T)
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

        lamda = dt/dx;

        std::vector<double>slope = slope_res(u[tik]);

        u.push_back(newtime_row);


    
    // Use second stage Runge-Kutta, which has second order accuracy, notice slope should be one more indice



    // consider boundary condition, i = 0,  i = n-1

    for (int j = 1;j<N-1;j++)
    {

       // calculate first stage of R-K

        ul_plus = u[tik][j] + 0.5*dx*slope[j+1];

        ur_plus = u[tik][j+1] - 0.5*dx*slope[j+2];

        ul_minus = u[tik][j-1] + 0.5*dx*slope[j];

        ur_minus = u[tik][j] - 0.5*dx*slope[j+1];

        L_Un = -1*lamda*( Godunov_flux_Burgers(ul_plus,ur_plus) - Godunov_flux_Burgers(ul_minus,ur_minus) );

        u_star[j] = u[tik][j] + dt*L_Un;

        u[tik+1][j] = 0.5*u[tik][j] + 0.5*(u_)











    }












  }

    
}



