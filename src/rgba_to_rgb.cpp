#include "rgba_to_rgb.h"
#include <iostream>

void rgba_to_rgb(
  const std::vector<unsigned char> & rgba,
  const int & width,
  const int & height,
  std::vector<unsigned char> & rgb)
{
  rgb.resize(height*width*3);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  int temp = 0;
  for (int i =0; i<width*height*4; i++){
    if (i%4 != 3){
      rgb[temp] = rgba[i];
      temp++;
    }
  }

  ////////////////////////////////////////////////////////////////////////////
}
