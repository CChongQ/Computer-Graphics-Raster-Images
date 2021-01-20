#include "hsv_to_rgb.h"
#include <cmath>

void hsv_to_rgb(
  const double h,
  const double s,
  const double v,
  double & r,
  double & g,
  double & b)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  // r = 0.0;
  // g = 0.0;
  // b = 0.0;

  double c = v*s;
  double h_p = h/60.0;
  double x = c*(1.0 - std::fabs(std::fmod( h_p,2.0)-1.0));

  if ( h_p >= 0.0 && h_p <= 1.0){
    r = c;
    g = x;
    b = 0.0;
  }
  else if ( h_p > 1.0 && h_p <= 2.0 ){
    r = x;
    g = c;
    b = 0.0;
  }
  else if ( h_p > 2.0 && h_p <= 3.0 ){
    r = 0.0;
    g = c;
    b = x;
  }
  else if ( h_p > 3.0 && h_p <= 4.0 ){
    r = 0.0;
    g = x;
    b = c;
  }
  else if ( h_p > 4.0 && h_p <= 5.0 ){
    r = x;
    g = 0.0;
    b = c;
  }
  else if ( h_p > 5.0 && h_p <= 6.0 ){
    r = c;
    g = 0.0;
    b = x;
  }
  else{
    r,g,b = 0.0;
  }

  double m = v-c;
  r+=m;
  g+=m;
  b+=m;

  ////////////////////////////////////////////////////////////////////////////
}
