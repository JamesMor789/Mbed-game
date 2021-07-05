#include "Arrow.h"

Arrow::Arrow() {}  // Constuctor
Arrow::~Arrow() {}  // Destructor

void Arrow::set_x_posit(int x,int x1,int x2)
{
  x_posit = x;   // x cordinate to be whatever x_arrow is set to in the engine
  x_posit1 = x1; // x cordinate to be whatever x_arrow1 is set to in the engine
  x_posit2 = x2; // x cordinate to be whatever x_arrow2 is set to in the engine
}

void Arrow::set_y_posit(double y)
{
  y_posit = y; // y cordinate to be whatever y_arrow is set to in the engine
}

void Arrow::draw(N5110 &lcd) // Creates the array for the arrow sprite
{
  const int pro_arrow[11][5] = { // Array for the arrow, 1=pixel turn on
    { 0,0,0,0,0, },
    { 0,1,1,1,0, },
    { 0,0,1,0,0, },
    { 0,1,1,1,0, },
    { 0,0,1,0,0, },
    { 0,0,1,0,0, },
    { 0,0,1,0,0, },
    { 1,0,1,0,1, },
    { 0,1,1,1,0, },
    { 0,0,1,0,0, },
    { 0,0,0,0,0, },

  }; 
  //Draws the arrows dependant on their cordinates.
  lcd.drawSprite(x_posit,y_posit,11,5,(int *)pro_arrow);
  lcd.drawSprite(x_posit1,y_posit,11,5,(int *)pro_arrow);
  lcd.drawSprite(x_posit2,y_posit,11,5,(int *)pro_arrow);
  
  //printf("x cordinate for arrow 1 is %i\n" , x_posit); 
  //printf("x cordinate for arrow 2 is %i\n" , x_posit1); 
  //printf("x cordinate for arrow 3 is  %i\n" , x_posit2); 
  //printf("y cordinate for all arrows  is %i\n" , y_posit); 
}