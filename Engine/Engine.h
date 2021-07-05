/** Engine class
* @brief A class that brings everything in the other classes together
* @author James Morley
* @date 06/05/2020
*/

#ifndef ENGINE_H
#define ENGINE_H

#include "mbed.h"
#include "Gamepad.h"
#include "N5110.h"
#include "Arrow.h"
#include "Knight.h"
#include "Scenery.h"
#include "Collision.h"
#include "Images.h"

class Engine {

  public:
  /** Constructor */
  Engine();
  /** Destructor */
  ~Engine();
  
  /** Initialses the values for the scenery and knight sprites and allows the 
      control of the knight
  * @param The lcd, A class for the N5110 display 
  * @param The pad, A class for the Gamepad 
  * @return The location of the knight
  * @return The location of the scenery 
  */
  void player_controling(N5110 &lcd,Gamepad &pad);

  /** Random number generators that set the cordinates for the arrows.
  * @return The x_arrow cordinates
  */
  void set_arrow_cordinates();
  
  /** Sets and displays the score in the game
  * param int x, where to place the score in the x-axis
  * param int y, where to place the score in the y-axis
  * @return The value of the score
  */ 
  void display_score(N5110 &lcd,int x,int y);
  
  /** Sets the speed of the arrow dependant on the score/level
  * @param The lcd, A class for the N5110 display 
  * @return The speed the arrows are moving
  * @return The level the user is on; displayed on the scrren
  */
  void arrow_speed(N5110 &lcd);
  
  /** Initiates all of the properties of the arrow
  * @param The lcd, A class for the N5110 display 
  * @return The positions of the arrows
  * @return The speed of the arrow
  * @return The score the player has achieved
  */
  void arrow_init(N5110 &lcd);
  
  /** Allows all the previous functions to work simultaneously
  * @param The y_cordinate for the arrow, a double( y_arrow)
  * @return The players position on the display
  * @return The arrows position on the display
  * @return If collision occurs between the player and the arrow
  */
  void game_loop(N5110 &lcd,Gamepad &pad);
  
  /** A function to check if collision has occured between the knight and arrow
  * @return If collision has occured
  */ 
  void collision_detection(N5110 &lcd,Gamepad &pad);
  
  /** Changes the state of the game once collision has occured
  * @param A loop, using variable t(double), to ensure the new state remains
  * @return The poisitions of the splash screen images
  * @return The final score
  * @return The message to inform that the game is over
  * @return The final splash screen images
  */
  void collision_state(N5110 &lcd, Gamepad &pad);
  
  private:
  int x_arrow; // The x-cordinate for first arrow 
  int x_arrow1; // The x-cordinate for second arrow 
  int x_arrow2;  // The x-cordinate for third arrow 
  double y_arrow;  // The y-cordinate for all the arrows 
  int score;  // The score the player is one
  float speed;  // The speed the arrow moves at
  Knight knight; 
  Arrow arrow;
  Scenery scenery;
  Collision col;
  Images images;
};
#endif