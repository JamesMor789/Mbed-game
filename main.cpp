/*
ELEC2645 Embedded Systems Project
School of Electronic & Electrical Engineering
University of Leeds
Name: James Morley
Username: ll17jm
Student ID Number: 201139411
Date:01/05/2020
*/

///////// pre-processor directives ////////
#include "mbed.h"
#include "Gamepad.h"
#include "N5110.h"
#include "Arrow.h"
#include "Knight.h"
#include "Engine.h"
#include "Scenery.h"
#include "Images.h"
#include <ctime>

#ifdef WITH_TESTING
# include "tests.h"
#endif

/////////////// objects ///////////////
Gamepad pad;
N5110 lcd;
Knight knight;
Arrow arrow;
Engine engine;
Scenery scenery;
Images images;

///////////// prototypes ///////////////
void first_init(); 
void start_screen(); 

///////////// functions ////////////////
int main() {

#ifdef WITH_TESTING
  int n_of_fails = run_tests();
  
  if(n_of_fails > 0) return n_of_fails;
  else {
    printf("passed");
  }
#endif
  
  first_init();  // Initialises the gamepad and scren 
  start_screen();  // A welcome screen that waits for start to be pressed

  while (1) {
    pad.leds_off();
    engine.game_loop(lcd, pad);
    lcd.refresh();
  }
}

//Initialises the gamepad and screen
void first_init()
{
  lcd.init();
  pad.init();
}

//This function displays the start screen when the device is powered on
void start_screen() 
{
  images.positions(36,15,20,48,20); // Initilaises the start screen sprite pos
  lcd.printString(" ARROW ATTACK!!", 0, 1);
  lcd.printString("  Press Start ", 0, 4);
  images.knight_start(lcd); // Draws the knight sprite on the start scren
  images.arrow_start(lcd); // Draws the arrow sprite on the start screen
  lcd.refresh();
  lcd.clear();

  //The LEDS continue to flash until the start button is pressed
  while (pad.start_pressed() == false) {
    lcd.setContrast(pad.read_pot1()); // Allows the user to set the contrast
    knight.left_lights(pad);  // Initilises the left pad LEDs to turn on
    wait(0.3);  // Hold the left LEDs on for 0.3s
    knight.right_lights(pad);  // Initilises the right pad LEDs to turn on
    wait(0.3);  // Hold the right LEDs on for 0.3s
  }
}