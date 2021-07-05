#include "Knight.h"

Knight::Knight(){}  // Constuctor
Knight::~Knight(){}  // Destructor

void Knight::init() // Starting postion for the knight
{
  x_knight = 42;  // x-cordinate for the knight
  y_knight = 33;  // y-cordinate for the knight
}

void Knight::draw(N5110 &lcd) // Draws the knight in the start pos
{
  const int man[15][9] =  {  // The array for the knight, 1=pixel turn on.
    {0,0,1,0,1,0,1,0,0},
    {0,0,0,1,1,1,0,0,0},
    {0,0,0,1,1,1,0,0,0},
    {0,0,0,0,1,0,0,0,0},
    {0,1,1,1,1,1,1,1,0},
    {0,1,0,1,1,1,0,1,0},
    {0,1,0,1,1,1,0,1,0},
    {0,1,0,1,1,1,0,1,0},
    {0,1,0,1,1,1,0,1,0},
    {0,0,0,1,0,1,0,0,0},
    {0,0,0,1,0,1,0,0,0},
    {0,0,0,1,0,1,0,0,0},
    {0,0,0,1,0,1,0,0,0},
    {0,0,0,1,0,1,0,0,0},
    {0,0,0,1,0,1,0,0,0},
    
    };
    //Draws the knight
    lcd.drawSprite(x_knight,y_knight,15,9,(int *)man);
}

void Knight::left_lights(Gamepad &pad) // Turns the left LEDs on
{
  pad.led(1,1);
  pad.led(2,1);
  pad.led(3,1);
  pad.led(4,0);
  pad.led(5,0);
  pad.led(6,0);
}

void Knight::right_lights(Gamepad &pad) //Turns the right LEDs on
{ 
  pad.led(1,0);
  pad.led(2,0);
  pad.led(3,0);
  pad.led(4,1);
  pad.led(5,1);
  pad.led(6,1);
}

void Knight::left_control(Gamepad &pad)
{
  x_knight -= 0.125f;  // How many pixels to move the knight
  //printf("X_knight value is %f\n" , x_knight); 
   
  if (pad.get_direction() == W && pad.A_held() == true) {
    x_knight -= 0.175f;
    //printf("X_knight value is %f\n after increasing speed" , x_knight);    
  }
}

void Knight::right_control(Gamepad &pad)
{
  x_knight += 0.125f;
  //printf("x_knight value is %f\n", x_knight); 
    
  if (pad.get_direction() == E && pad.A_held() == true) {
    x_knight += 0.175f;
    //printf("x_knight value is %f\n after increasing speed", x_knight);
  }
}

void Knight::boundries()
{
  if (x_knight < 15) { // Stops the knight going of the map(left side)
    x_knight = 16;
    //printf("x_knight value is %f after testing left boundry \n", x_knight); 
  }
  if (x_knight > 61) { // Stops the knight going of the map(right side)
    x_knight = 60;
    //printf("x_knight value is %f after testing right boundry \n", x_knight);
  }
  if (y_knight < 33) { // Stops the knight spawning in the top left
    y_knight = 31; 
    //printf("y_knight value is %f\n", y_knight); 
  }
}

void Knight::control(Gamepad &pad) // Changes the direction of movement
{
  direction = pad.get_direction();
  switch (direction) {
  
  case W: // Case: When the user pushes the joystick left
  left_control(pad); // Use the left control function
  boundries(); // Use the boundries function
  left_lights(pad); // The left LEDs will turn on
  break;
    
  case E:  // Case: When the user pushes the joystick right
  right_control(pad); // Use the right control function  
  boundries();  // Use the boundries function
  right_lights(pad);  // The right LEDs will turn on
  break;
  }  
}

void Knight::engine_control(Gamepad &pad) //Combines functions for the engine
{
  boundries(); // Boundries function, redeclared so the knight spawns correctly
  control(pad); // Allows control of the knight
}