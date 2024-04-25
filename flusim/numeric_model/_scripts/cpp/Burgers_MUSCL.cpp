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



std::vector<std::vector<double>> MUSCL_Burgers_dim1_bc1(std::vector<double> u0, int N, double T, double CFL, double left_bd, double right_bd)
{

    
}



