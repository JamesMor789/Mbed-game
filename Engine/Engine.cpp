#include "Engine.h"
#include<ctime>

Engine::Engine() {} // Constuctor     
Engine::~Engine() {} // Destructor

//Draws the needed sprites and allows control of the Knight
void Engine::player_controling(N5110 &lcd,Gamepad &pad)
{
  scenery.init(); // Initilises the values for the scenery sprite
  scenery.draw(lcd); // Draws the scenery
  knight.engine_control(pad); // Allows the knight to be controlled
  knight.draw(lcd); // Draws the knight according to the given cordinate values
}

//Sets the starting arrow cordinates
void Engine::set_arrow_cordinates()
{
  srand(time(NULL)); // Random seed is based on time; so it's never the same
  x_arrow = rand() % 18 + 15; // Random number generator within range(15-33)
  x_arrow1 = rand() % 9 + 38; // Random number generator within range(38-47)
  x_arrow2 = rand() % 8 + 56; // Random number generator within range(56-64)
}

//Displays the current score on the N5110 display
void Engine::display_score(N5110 &lcd,int x, int y)
{
  char buffer[1]; // This creates a char buffer of 1
  sprintf(buffer,"%2d",score); // Writes the string to the buffer
  lcd.printString(buffer,x,y); // Prints the string on the display
  lcd.refresh();
  
  //printf("The score is %i\n" , score); 
}

//Sets the speed of the arrow, dependant on the score the user has reached
void Engine::arrow_speed(N5110 &lcd)
{
  switch (score) {
   
  case 0 ... 5: // The score is in the range of 0 to 5
  speed = 0.1; // The speed is set
  lcd.printString("L1",72,1); // The level is displayed on the screen
  break;

  case 6 ... 10:
  speed = 0.12;
  lcd.printString("L2",72,1);
  break;

  case 11 ... 15:
  speed = 0.13;
  lcd.printString("L3",72,1);
  break;

  case 16 ... 20:
  speed = 0.14;
  lcd.printString("L4",72,1);
  break;

  case 21 ... 25:
  speed = 0.15;
  lcd.printString("L5",72,1);
  break;

  case 26 ... 30:
  speed = 0.16;
  lcd.printString("L6",72,1);
  break;

  default:
  speed = 0.2;
  lcd.printString("L7",72,1);
  }
  //printf("The score is %f\n" , speed); 
}

//Initiates the arrows properties needed for the game loop
void Engine::arrow_init(N5110 &lcd)
{
  set_arrow_cordinates(); // Sets the starting arrows cordinates
  arrow.set_x_posit(x_arrow, x_arrow1, x_arrow2); // Sets the coridinates, Arrow
  display_score(lcd,0,1); // Displays the score while the game is running
  arrow_speed(lcd); // Sets the speed, dependant on the score
}

//Brings all the previous components together, so they work similtansouly 
void Engine::game_loop(N5110 &lcd,Gamepad &pad)
{
  arrow_init(lcd); // Initialises the arrows properties 
  for (double n = 0; n < 48; n += speed) { // A loop so the arrow falls
    y_arrow = n; // Sets the y-cordinate for the arrow 
    arrow.set_y_posit(y_arrow); // Puts the y_arrow value into the arrow class
    arrow.draw(lcd); // Draws the arrow using the given cordinates
    player_controling(lcd, pad); // Allow control of the player
    collision_detection(lcd,pad); // Checks if collision has occured
    lcd.refresh();
  }
  score += 1; // Increases the score by 1 point, if the arrows were avoided
}

//Checks if collision has occured
void Engine::collision_detection(N5110 &lcd,Gamepad &pad)
{
  if (col.bottom(lcd, x_arrow, y_arrow) || col.bottom(lcd, x_arrow1, y_arrow) ||
      col.bottom(lcd, x_arrow2, y_arrow) == 1) {
        collision_state(lcd, pad); // Changes game state if collision occured
  }
}
 
// Changes the game state depedening on if the collisoin returns true 
void Engine::collision_state(N5110 & lcd, Gamepad & pad) 
{
  pad.tone(850.0, 0.1); // Plays a tone to signify collision has occured
  lcd.clear();
  pad.leds_on();
  for (double t = 0; t < 100000; t += 0.1) { // A loop so this state continues 
    lcd.refresh();
    lcd.printString("   YOU DIED   ", 1, 1); // Displays "YOU DIED"
    lcd.printString(" Score =  ", 5, 2); // Displays "YOU DIED"
    lcd.printString(" Press Reset", 4, 3); // Displays "Press Reset"
    display_score(lcd,55,2);  // Displays the score 
    images.engine(lcd);  // Initiliases and displays the end screen sprites
  }
} 