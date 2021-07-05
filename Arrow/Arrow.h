/** Arrow class
* @brief This will create and draw the arrow
* @author James Morley
* @date 1/05/2020
*/

#ifndef ARROW_H
#define ARROW_H

#include "mbed.h"
#include "Gamepad.h"
#include "N5110.h"

class Arrow {

  public:

  /** Constructor */
  Arrow();

  /** Destructor */
  ~Arrow();

  /** Set the x position
  * @param int x, the x-cordinate for arrow 1
  * @param int x1, the x-cordinate for arrow 2
  * @param int x2, the x-cordinate for arrow 3
  */
  void set_x_posit(int x,int x1, int x2); 

  /** Set the y position
  * @param double y, the y-cordinate for the arrow
  */
  void set_y_posit(double y);

  /** Draws the arrow
  * @param The lcd, A class for the N5110 display 
  * @return The sprite drawn on the screen
  */
  void draw(N5110 &lcd); 
  
  private:
  int x_posit;        // x-cordinate for arrow 1
  int x_posit1;       // x-cordinate for arrow 2
  int x_posit2;       // x-cordinate for arrow 3
  int y_posit;        // y-cordinate for all arrows
  N5110 lcd;
};
#endif