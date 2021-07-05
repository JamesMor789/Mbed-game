/** Scenery class
* @brief These are the  objects that are constantly in the background
* @author James Morley
* @date 1/05/2020
*/

#ifndef SCENERY_H
#define SCENERY_H

#include "mbed.h"
#include "Gamepad.h"
#include "N5110.h"

class Scenery {
  
  public:
  /** Constructor */
  Scenery();
  /** Destructor */
  ~Scenery();

  /** Initialises the cordinates for the scenery sprites
  * @param The cordinate values for both scenery sprites(int)
  */
  void init();

  /** Intialises the scenery array and draws the scenery sprite
  * @param lcd, the object for N5110 that allows use of the screen
  * @param The scenery sprite array
  */
  void draw(N5110 &lcd); 
   
  private:
  int x_scenery;  // x-cordinate for the scenery background 1
  int x1_scenery; // x-cordinate for the scenery background 2
  int y_scenery;  // y-cordinate for the scenery background 1
  int y1_scenery; // y-cordinate for the scenery background 2
};
#endif