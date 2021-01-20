#include "rgb_to_gray.h"

void rgb_to_gray(
  const std::vector<unsigned char> & rgb,
  const int width,
  const int height,
  std::vector<unsigned char> & gray)
{
  gray.resize(height*width);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  for(int row=0; row<height; row++ ){
    for (int col =0; col<width; col++){
      //0.2126r + 0.7152g + 0.0722b
      gray[col+width*row]= 0.2126 * rgb[3*(col+width*row)]+ 0.7152*rgb[3*(col+width*row)+1] + 0.0722 * rgb[3*(col+width*row)+2];
    }
  }

  ////////////////////////////////////////////////////////////////////////////
}


