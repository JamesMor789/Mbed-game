/** Knight class
* @brief A class to create and control the knight
* @author James Morley
* @date 1/05/2020
*/

#ifndef KNIGHT_H
#define KNIGHT_H

#include "mbed.h"
#include "Gamepad.h"
#include "N5110.h"

class Knight {

  public:

  /** Constructor */
  Knight();
  
  /** Destructor */
  ~Knight();

  /** Initialises the starting postion of the knight
  * @return The cordinate values for the knight sprite
  */
  void init();

  /** Initialises the knight sprite array and draws the knight
  * @param The lcd, A class for the N5110 display 
  * @return The knight sprite array
  */
  void draw(N5110 &lcd);
  
  /** Turns on the left-side LEDS and turns off the right side LEDs
  * @param The pad, A class for the gamepad 
  * @return The condition of each individual LED
  */
  void left_lights(Gamepad &pad);
  
  /** Turns on the right-side LEDS and turns off the left side LEDs
  * @param The pad, A class for the gamepad
  * @return The condtion of each individual LED
  */
  void right_lights(Gamepad &pad);
  
  /** Changes the x-cordinate for the knight if the joystick is pushed left
  * @param The pad, A class for the gamepad
  * @param Edits the x_knight value (float)
  */
  void left_control(Gamepad &pad);
  
  /** Changes the x-cordinate for the knight if the joystick is pushed right
  * @param The pad, A class for the gamepad
  * @param Edits the x_knight value (float)
  */
  void right_control(Gamepad &pad);
  
  /** Prevents the knight from walking off screen or into solid objects
  * @param Edits x_knight(float) and y_knight(int)
  */ 
  void boundries();
  
  /** Switches the condtions dependant on where the joystick is pushed
  * @param The pad, A class for the gamepad
  * @param Direction, W & E from the gamepad
  */
  void control(Gamepad &pad);
  
  /** Pulls together the functions in knight.ccp to be used in engine.cpp
  * @param The pad, A class for the gamepad
  */
  void engine_control(Gamepad &pad);
  
  private: 
  float x_knight; // x-cordinate for the knight
  int y_knight;  // y-cordinate for the knight
  int direction; // The direction in which the joystick is pushed
};
#endif