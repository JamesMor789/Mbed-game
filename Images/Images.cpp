#include "Images.h"

Images::Images(){}  // Constuctor
Images::~Images(){}  // Destructor 

void Images::knight_start(N5110 &lcd)
{
  const int knight_intro[16][13] = { //The array for the knight, 1=pixel turn on
    {0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,1,0,1,0,1,0,0,0,0,0,0},
    {0,0,0,1,1,1,0,0,0,0,0,0,0},
    {0,0,0,1,1,1,0,0,0,0,0,0,0},
    {0,0,0,0,1,0,0,0,0,0,0,0,0},
    {0,1,1,1,1,1,1,1,0,0,0,0,0},
    {0,1,0,1,1,1,0,1,0,0,0,0,0},
    {0,1,0,1,1,1,0,1,0,0,0,0,0},
    {0,1,0,1,1,1,0,1,0,0,0,0,0},
    {0,1,0,1,1,1,0,1,0,1,0,0,0},
    {0,0,0,1,0,1,0,0,1,0,0,0,0},
    {0,0,0,1,0,1,0,1,0,1,0,0,0},
    {0,0,0,1,0,1,0,0,0,0,1,0,0},
    {0,0,0,1,0,1,0,0,0,0,0,1,0},
    {0,0,0,1,0,1,0,0,0,0,0,0,0},
    {0,0,0,1,0,1,0,0,0,0,0,0,0},
    };
    
    //draws the knight
    lcd.drawSprite(x_knight_S,y_knight_S,16,13,(int *)knight_intro);
    //printf("The pos of the knight is %i %i\n", x_knight_S, y_knight_S); 
}

void Images::arrow_start(N5110 &lcd)
//The array for the arrows, 1=pixel turn on.
{
  const int arrow_intro_left[5][13] = {
    {0,0,1,0,0,0,0,0,0,0,1,0,0},
    {1,0,0,1,0,0,0,0,0,0,1,1,0},
    {1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,0,1,0,0,0,0,0,0,1,1,0},
    {0,0,1,0,0,0,0,0,0,0,1,0,0},
    };
    
  const int arrow_intro_right[5][13] = {
    {0,0,1,0,0,0,0,0,0,0,1,0,0},
    {0,1,1,0,0,0,0,0,0,1,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1},
    {0,1,1,0,0,0,0,0,0,1,0,0,1},
    {0,0,1,0,0,0,0,0,0,0,1,0,0},
    };
    
    //Draws the arrows
    lcd.drawSprite(x_arrow_S_R,y_arrow_S,5,13,(int *)arrow_intro_left);
    lcd.drawSprite(x_arrow_S_L,y_arrow_S,5,13,(int *)arrow_intro_right);
    //printf("The pos(s) of the arrow is %i %i\n", x_arrow_S_R, x_arrow_S_L); 
}

void Images::knight_death(N5110 &lcd)
{
  const int knight_dead[14][11] = {
    {0,0,0,0,0,0,0,0,0,0,0},
    {0,1,0,0,0,1,0,0,0,1,0},
    {1,0,1,0,1,0,1,0,1,0,1},
    {1,0,1,0,1,0,1,0,1,0,1},
    {1,1,1,1,1,1,1,1,1,1,1},
    {0,1,0,0,0,0,0,0,0,1,0},
    {1,0,1,0,1,0,1,0,1,0,1},
    {1,0,0,1,0,0,0,1,0,0,1},
    {1,0,1,0,1,0,1,0,1,0,1},
    {1,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,1,1,1,0,0,0,1},
    {0,1,0,1,0,0,0,1,0,1,0},
    {0,0,1,0,0,0,0,0,1,0,0},
    {0,0,0,1,1,1,1,1,0,0,0},
    };
    
    lcd.drawSprite(x_death,y_death,14,11,(int *)knight_dead);
}

void Images::death_pos()
{
  x_death=35;  // The x-cordinate for the dead man sprite
  y_death=33;  // The y-cordinate for the dead man sprite
}

void Images::positions(int x_k, int y_k, int x_a_r, int x_a_l, int y_a)
{
  x_knight_S = x_k; // The x-cordinate for the knight, used in the splash screens
  y_knight_S = y_k;  // The y-cordinate for the knight, used in the splash screens
  x_arrow_S_R = x_a_r;  // The x-cordinate for the right side arrow
  x_arrow_S_L = x_a_l;  // The x-cordinate for the left side arrow
  y_arrow_S = y_a;  // The y-cordinate for the arrow, used in the splash screens
}    

void Images::engine(N5110 &lcd)
{
  death_pos();
  positions(36,30,22,46,40);
  arrow_start(lcd);
  knight_death(lcd);
}