#include "desaturate.h"
#include "hsv_to_rgb.h"
#include "rgb_to_hsv.h"

void desaturate(
  const std::vector<unsigned char> & rgb,
  const int width,
  const int height,
  const double factor,
  std::vector<unsigned char> & desaturated)
{
  desaturated.resize(rgb.size());
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here

  for(int row=0; row<height; row++ ){
    for (int col =0; col<width; col++){
      double r = rgb[3*(col+width*row)];
      double g = rgb[3*(col+width*row)+1];
      double b = rgb[3*(col+width*row)+2];
      
      double h,s,v = 0;
      rgb_to_hsv(r,g,b,h,s,v);
      s = s*(1-factor);
      hsv_to_rgb(h,s,v,r,g,b);
      
      desaturated[3*(col+width*row)] = r;
      desaturated[3*(col+width*row)+1] = g;
      desaturated[3*(col+width*row)+2] = b;

    }
  }
  ////////////////////////////////////////////////////////////////////////////
}
