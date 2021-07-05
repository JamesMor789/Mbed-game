#ifndef KNIGHT_TEST_H
#define KNIGHT_TEST_H

bool knight_test_boundries() 
{
  Knight knight // Initiliases the knight object 
  knight.init(); // Initiliases the starting cordinates for the knight 
  printf("%f\n", x_knight); // Prints the x-cordinate for the knight
  
  x_knight = 100; // Sets the x-cordinate to 100
  printf("%f\n", x_knight);// Prints the new cordinate
  
  bool success_flag = true;
  
  if (x_knight > 60) { // Checks if the knight has returned to the boundry
      success_flag = false;
  }
  return success_flag;
}
#endif