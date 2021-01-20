#include "rgb_to_hsv.h"
#include <algorithm>
#include <cmath>

void rgb_to_hsv(
  const double r,
  const double g,
  const double b,
  double & h,
  double & s,
  double & v)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  // h = 0;
  // s = 0;
  // v = 0;

  double max = std::max({r,g,b});
  double min = std::min({r,g,b});
  double range = max - min;

  v = max;

  if (range == 0.0){
    h = 0.0;
  }
  else if (v == r){
    h = 60.0 * (0.0 +(g-b)/range);
  }
  else if (v == g){
    h = 60.0 * (2.0 +(b-r)/range);
  }
  else if (v == b){
    h = 60.0 * (4.0 +(r-g)/range);
  }
  
  if (h>360) h = std::fmod(h,360);
  while (h<0) h = h+360;

  if (v == 0.0){
    s = 0.0;
  }
  else{
    s = range / v;
  }

  

  ////////////////////////////////////////////////////////////////////////////
}
