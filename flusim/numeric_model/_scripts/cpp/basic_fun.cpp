#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include "functions_lib.h"

// sign function to calculate sign
int sign(double x)
{

  return (x>0) - (x<0);

}

double diff_1_minus_2(double a, double b)
{
  return a - b;
}


// find the largest element in a vector

double max_elementof_vector(std::vector<double> v)
{

double tmp = -10000.0;

int len = v.size();

for (int i =0;i <len;i++)
{
  if (tmp<=v[i])
  {
    tmp = v[i];
  }

}

return tmp;

}

// minmod function

double minmod(double a, double b)
{
   return 0.5*(sign(a) + sign(b)) * std::min(std::abs(a),std::abs(b));


}

// flux function for Burgers equation

double Burgers_f(double x)
{
    return 0.5*x*x;
}

// first order derivative of flux function of Burgers equation


double Burgers_df(double x)
{
  return x;
}


// Godunov flux for Burgers equation

double Godunov_flux_Burgers(double ul, double ur)
{
   
   double fG = 0;

   if (ul>=ur)
   {
      if (Burgers_f(ul) >= Burgers_f(ur))
      {
        return Burgers_f(ul);
      }
      else return Burgers_f(ur);

   }

   else if (ul<ur)
   {
    if (Burgers_df(ul)>=0)
    {
        return Burgers_f(ul);
    }
    else if (Burgers_df(ur)<0)
    {
        return Burgers_f(ur);
    }
   }
   else return 0;

}