#include "reflect.h"

void reflect(
  const std::vector<unsigned char> & input,
  const int width,
  const int height,
  const int num_channels,
  std::vector<unsigned char> & reflected)
{
  reflected.resize(width*height*num_channels);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  for(int row=0; row<height; row++ ){
    for (int col =0; col<width; col++){
      if (num_channels == 3){
        reflected[3*(col+width*row)] = input[3*(width*(row+1)-col)-3];//r
        reflected[1+3*(col+width*row)] = input[3*(width*(row+1)-col)-2]; //g
        reflected[2+3*(col+width*row)] = input[3*(width*(row+1)-col)-1]; //b
      }
      else if (num_channels == 1){
         reflected[col+width*row] = input[width*(row+1)-col-1];
      }
     
    }
  }

  ////////////////////////////////////////////////////////////////////////////
}
