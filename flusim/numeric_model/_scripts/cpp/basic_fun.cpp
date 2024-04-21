#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include "functions_lib.h"

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
