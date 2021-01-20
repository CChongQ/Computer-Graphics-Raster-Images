#include "demosaic.h"

void demosaic(
  const std::vector<unsigned char> & bayer,
  const int & width,
  const int & height,
  std::vector<unsigned char> & rgb)
{
  rgb.resize(width*height*3);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  /*
    G B G B
    R G R G
    G B G B
    R G R G
  */
 for(int row=0; row<height; row++ ){
    for (int col =0; col<width; col++){
      /*--------------G--------------*/
      if (row % 2 == 0 && col % 2 == 0){
          //G
          rgb[3*(col+width*row)+1] = bayer[col+width*row];
          //B
          if (col == 0) 
            rgb[3*(col+width*row)+2] = bayer[col+1+width*row];   
          else
            rgb[3*(col+width*row)+2] =  (bayer[col-1+width*row] + bayer[col+1+width*row])/2;
          //R
          if (row == 0 ){
            rgb[3*(col+width*row)] = bayer[col+width*(row+1)]; 
          }
          else if (row == height -1){
            rgb[3*(col+width*row)] = bayer[col+width*(row-1)];
          }
          else{
            rgb[3*(col+width*row)] = (bayer[col+width*(row-1)] + bayer[col+width*(row+1)])/2;
          }
      }
      else if (row % 2 == 1 && col % 2 == 1){
        //G
        rgb[3*(col+width*row)+1] = bayer[col+width*row];
        //B
        if (row == height -1){
          rgb[3*(col+width*row)+2] = bayer[col+width*(row-1)];  
        }
        else{
          rgb[3*(col+width*row)+2] = (bayer[col+width*(row-1)] +  bayer[col+width*(row+1)])/2  ; 
        }
        //R
        if (col == width -1){
          rgb[3*(col+width*row)] = bayer[col-1+width*row]; 
        }
        else{
          rgb[3*(col+width*row)] = (bayer[col-1+width*row] + bayer[col+1+width*row])/2; 
        }
      }

      /*--------------B--------------*/
      else if (row % 2 == 0 && col % 2 == 1){
        //B
        rgb[3*(col+width*row)+2] = bayer[col+width*row];  
        //G & R
        if (row == 0){
          if (col != width -1){
            rgb[3*(col+width*row)+1] = (bayer[col-1+width*row] + bayer[col+1+width*row] + bayer[col+width*(row+1)] )/3;//G
            rgb[3*(col+width*row)] =  (bayer[col-1+width*(row+1)] + bayer[col+1+width*(row+1)])/2;//R
          }
          else {
            rgb[3*(col+width*row)+1] = (bayer[col-1+width*row] + bayer[col+width*(row+1)] )/2;//G
            rgb[3*(col+width*row)] =  bayer[col-1+width*(row+1)]; //R
          }  
        }
        else if (row == height -1){
          if (col != width -1){
            rgb[3*(col+width*row)+1] = (bayer[col-1+width*row] + bayer[col+1+width*row] + bayer[col+width*(row-1)] )/3;//G
            rgb[3*(col+width*row)]  =  (bayer[col-1+width*(row-1)] + bayer[col+1+width*(row-1)])/2;//R
          }
          else{         
            rgb[3*(col+width*row)+1] = (bayer[col-1+width*row] + bayer[col+width*(row-1)] )/2;//G 
            rgb[3*(col+width*row)] =  bayer[col-1+width*(row-1)]; //R
          }
        }
        else if (col == width -1){        
          rgb[3*(col+width*row)+1] = (bayer[col-1+width*row] +bayer[col+width*(row-1)] + bayer[col+width*(row+1)])/3;//G      
          rgb[3*(col+width*row)]  =  (bayer[col-1+width*(row-1)] + bayer[col-1+width*(row+1)])/2;//R
        }
        else{         
           rgb[3*(col+width*row)+1] = (bayer[col-1+width*row] + bayer[col+1+width*row] + bayer[col+width*(row-1)] + bayer[col+width*(row+1)] )/4;//G
           rgb[3*(col+width*row)] = (bayer[col-1+width*(row-1)] + bayer[col+1+width*(row-1)] + bayer[col-1+width*(row+1)] + bayer[col+1 +width*(row+1)] )/4;//R
        }
        
      }
      
      /*--------------R--------------*/
      else if (row % 2 == 1 && col % 2 == 0){
        //R
        rgb[3*(col+width*row)] = bayer[col+width*row]; 
        //G & B
        if (col == 0){
          if (row != height -1){
            rgb[3*(col+width*row)+1] = (bayer[col+1+width*row] + bayer[col+width*(row-1)] + bayer[col+width*(row+1)])/3;//G
            rgb[3*(col+width*row)+2] = (bayer[col+1+width*(row-1)] + bayer[col+1+width*(row+1)])/2;//B
          }
          else{
            
            rgb[3*(col+width*row)+1] = (bayer[col+1+width*row] +bayer[col+width*(row-1)])/2;  //G
            
             rgb[3*(col+width*row)+2] = bayer[col+1+width*(row-1)] ;//B
          }  
        }
        if (col == width -1){
           if (row != height -1){
            rgb[3*(col+width*row)+1] = (bayer[col-1+width*row] +bayer[col+width*(row-1)] + bayer[col+width*(row+1)])/3;//G
            rgb[3*(col+width*row)+2] = (bayer[col-1+width*(row-1)] + bayer[col-1+width*(row+1)])/2;//B
           }
          else{
            rgb[3*(col+width*row)+1] = (bayer[col-1+width*row] +bayer[col+width*(row-1)])/2;  //G
            rgb[3*(col+width*row)+2] = bayer[col-1+width*(row-1)] ;//B
          }
        }
        else{
          rgb[3*(col+width*row)+1] = (bayer[col-1+width*row] + bayer[col+1+width*row] + bayer[col+width*(row-1)] + bayer[col+width*(row+1)] )/4;//G
          rgb[3*(row*width+col)+2] = (bayer[(row-1)*width+col-1] + bayer[(row+1)*width+col+1]) / 2;//B
        }
      }
    }
 }

  ////////////////////////////////////////////////////////////////////////////
}
