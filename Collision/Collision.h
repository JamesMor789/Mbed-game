/** Collision class
* @brief A class that checks if the arrow has hit the player
* @author James Morley
* @date 09/05/2020
*/

#ifndef COLLISION_H
#define COLLISION_H

#include "mbed.h"
#include "N5110.h"
#include "Gamepad.h"

class Collision {

  public:
  
  /** Constructor */
  Collision();
  
  /** Destructor */
  ~Collision();

  /** Checks if the pixel below the arrow has hit another activated pixel
  * @param int x, the x-cordinate which relates to the x_arrow value
  * @param int y, the y-cordinate which relates to the y_arrow value
  * @return Return true if a activated pixel is detected, false if not
  */
  bool bottom(N5110 &lcd, int x, int y);
};
#endif