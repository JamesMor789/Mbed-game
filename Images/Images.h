/** Images class
* @brief A class that contains the still images for the start and end screens
* @author James Morley
* @date 13/05/2020
*/

#ifndef IMAGES_H
#define IMAGES_H

#include "mbed.h"
#include "Gamepad.h"
#include "N5110.h"

class Images {

  public:
  
  /** Constructor */
  Images();
  
  /** Destructor */
  ~Images();
  
  /** Draws the knight for the start and end splash screens
  * @return The sprites position; displayed on the screen
  */
  void knight_start(N5110 &lcd);
  
  /** Draws the arrow for the start and end splash screens
  * @returm The arrows position; displayed on the screen.
  */
  void arrow_start(N5110 &lcd);
  
  /** Draws the dead man for the end splash screen
  * @return The dead mans position; displayed on the screen
  */
  void knight_death(N5110 &lcd);
  
  /** Initiates the cordinates for the dead man sprite
  / @return The cordinates for the dead man sprite
  */
  void death_pos();
  
  /** Initiates the cordinates for arrow/knight sprites for the start screen
  * @param The cordinates for the sprites (int)
  */
  void positions(int x_k, int y_k, int x_a_r, int x_a_l, int y_a);
  
  /** Brings the functions in the images class together for use in the engine
  * @param lcd, the object for N5110 that allows use of the screen
  * @return displays the sprite on the display
  */
  void engine(N5110 &lcd);
  
  private:
  int x_death;  // The x-cordinate for the dead man, used in the end screen
  int y_death;  // The y-cordinate for the dead man, used in the end screen  
  int x_knight_S; // The x-cordinate for the knight, used in the splash screens
  int y_knight_S; // The y-cordinate for the knight, used in the splash screens
  int x_arrow_S_R; // The x-cordinate for the right side arrow
  int x_arrow_S_L; // The x-cordinate for the left side arrow
  int y_arrow_S;  // The y-cordinate for the arrow, used in the splash screens
};
#endif