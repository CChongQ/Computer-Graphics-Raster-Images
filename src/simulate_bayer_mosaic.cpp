#include "simulate_bayer_mosaic.h"

void simulate_bayer_mosaic(
  const std::vector<unsigned char> & rgb,
  const int & width,
  const int & height,
  std::vector<unsigned char> & bayer)
{
  bayer.resize(width*height);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  /*
    G B G B
    R G R G
  */
   for(int row=0; row<height; row++ ){
    for (int col =0; col<width; col++){
      //G
      if ( (row%2 == 0 && col%2 == 0) || (row%2 == 1 && col%2 == 1) ){
        bayer[col+width*row] = rgb[3*(col+width*row)+1];
      }
      //B
      else if ( row%2 == 0 && col%2 == 1 ){
         bayer[col+width*row] = rgb[3*(col+width*row)+2];
      }
      //R
      else{
         bayer[col+width*row] = rgb[3*(col+width*row)];
      }
    }
  }
  ////////////////////////////////////////////////////////////////////////////
}
