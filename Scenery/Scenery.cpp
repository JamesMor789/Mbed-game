#include "Scenery.h"

Scenery::Scenery() {}  // Constuctor
Scenery::~Scenery() {}  // Destructor

//Initiates the cordinates for the scenery sprite
void Scenery::init()
{
  x_scenery=0;    // x-cordinate for the scenery background 1
  x1_scenery=69;  // x-cordinate for the scenery background 2
  y_scenery=24;   // y-cordinate for the scenery background 1
  y1_scenery=24;  // y-cordinate for the scenery background 2
}

//Initiates The array for the scenery sprite and draws it
void Scenery::draw(N5110 &lcd)
{
  const int scenery_castle[24][15] = {  // The array for the scenery
    {1,1,1,0,0,0,1,1,1,0,0,0,1,1,1},
    {1,0,1,0,0,0,1,0,1,0,0,0,1,0,1},
    {1,0,1,0,0,0,1,0,1,0,0,0,1,0,1},
    {1,0,1,0,0,0,1,0,1,0,0,0,1,0,1},
    {1,0,1,0,0,0,1,0,1,0,0,0,1,0,1},
    {1,0,1,1,1,1,1,0,1,1,1,1,1,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,1,1,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,1,1,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,1,1,0,0,0,0,0,0,1},
    {1,0,1,1,1,1,1,1,1,1,1,1,1,0,1},
    {1,0,1,1,1,1,1,1,1,1,1,1,1,0,1},
    {1,0,0,0,0,0,1,1,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,1,1,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,1,1,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,1,1,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,1,1,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,1,1,1,1,0,0,0,0,0,1},
    {1,0,0,0,0,1,0,0,1,0,0,0,0,0,1},
    {1,0,0,0,0,1,0,0,1,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  
  };
  //draws the scenery
  lcd.drawSprite(x_scenery,y_scenery,24,15,(int *)scenery_castle);
  lcd.drawSprite(x1_scenery,y1_scenery,24,15,(int *)scenery_castle);
}