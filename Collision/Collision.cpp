#include "Collision.h"

Collision::Collision() {} // Constuctor
Collision::~Collision() {} // Destructor

/*Checks if any pixels below the arrow are activated.
  Varibles x and y are dependant on x_arrow and y_arrow, which are determined in
  engine.cpp.
*/
bool Collision::bottom(N5110 & lcd, int x, int y) {
  if (lcd.getPixel(x + 1, y + 10) == 1) {
    return true;
  } else if (lcd.getPixel(x + 2, y + 10) == 1) {
    return true;
  } else if (lcd.getPixel(x + 3, y + 10) == 1) {
    return true;
  } else {
    return false;
  }
}