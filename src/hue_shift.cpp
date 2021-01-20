#include "hue_shift.h"
#include "hsv_to_rgb.h"
#include "rgb_to_hsv.h"
#include <cmath>

void hue_shift(
  const std::vector<unsigned char> & rgb,
  const int width,
  const int height,
  const double shift,
  std::vector<unsigned char> & shifted)
{
  shifted.resize(rgb.size());
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here

  for(int row=0; row<height; row++ ){
    for (int col =0; col<width; col++){
      double r = rgb[3*(col+width*row)];
      double g = rgb[3*(col+width*row)+1];
      double b = rgb[3*(col+width*row)+2];
      
      double h,s,v = 0;
      rgb_to_hsv(r,g,b,h,s,v);
      h = h+shift;
      if (h>360) h = std::fmod(h,360);
      hsv_to_rgb(h,s,v,r,g,b);
      
      shifted[3*(col+width*row)] = r;
      shifted[3*(col+width*row)+1] = g;
      shifted[3*(col+width*row)+2] = b;

    }
  }
  ////////////////////////////////////////////////////////////////////////////
}
