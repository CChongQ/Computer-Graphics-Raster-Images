#include "rotate.h"

void rotate(
  const std::vector<unsigned char> & input,
  const int width,
  const int height,
  const int num_channels,
  std::vector<unsigned char> & rotated)
{
  rotated.resize(height*width*num_channels);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
   for(int row=0; row<height; row++ ){
    for (int col =0; col<width; col++){
      if (num_channels == 3){
        rotated[3*(row+(width-col-1)*height)] = input[3*(col+width*row)];//r
        rotated[3*(row+(width-col-1)*height)+1] = input[3*(col+width*row)+1]; //g
        rotated[3*(row+(width-col-1)*height)+2] = input[3*(col+width*row)+2];//b
      }
      else if (num_channels == 1){
         rotated[3*(row+(width-col-1)*height)] = input[3*(col+width*row)];
      }
    
     
    }
  }
  ////////////////////////////////////////////////////////////////////////////
}
