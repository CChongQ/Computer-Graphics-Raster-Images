#include "over.h"

void over(
  const std::vector<unsigned char> & A,
  const std::vector<unsigned char> & B,
  const int & width,
  const int & height,
  std::vector<unsigned char> & C)
{
  C.resize(A.size());
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here

  for(int row=0; row<height; row++ ){
    for (int col =0; col<width; col++){
      double r_A = (double)A[4*(col+width*row)];
      double g_A = (double)A[4*(col+width*row)+1];
      double b_A = (double)A[4*(col+width*row)+2];
      double alpha_A = (double)A[4*(col+width*row)+3] / 255; 

      double r_B = (double)B[4*(col+width*row)];
      double g_B = (double)B[4*(col+width*row)+1];
      double b_B = (double) B[4*(col+width*row)+2];
      double alpha_B = (double) B[4*(col+width*row)+3] / 255;

      //C = alpha * Cf + (1- alpha)*Cb
      C[4*(col+width*row)] = (unsigned char) (alpha_A * r_A + (1-alpha_A) * r_B);
      C[4*(col+width*row)+1] = (unsigned char) (alpha_A  * g_A + (1-alpha_A) * g_B);
      C[4*(col+width*row)+2] = (unsigned char) (alpha_A  * b_A + (1-alpha_A) * b_B);
      C[4*(col+width*row)+3] = (unsigned char) (alpha_A + (1-alpha_A) * alpha_B);//alpha
    }
  }

  ////////////////////////////////////////////////////////////////////////////
}
