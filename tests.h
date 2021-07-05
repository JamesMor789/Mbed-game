#ifndef TESTS_H
#define TESTS_H

#include "Knight-test.h" 

int run_tests()
{
  int n_fails = 0; // Initiliases the number of fails to 0
  
  printf("Testing knight_boundry...\n");
  bool test_result = knight_test_boundries(); // Initiliases test_result
  
  if (test_result==true) {
    printf("...Passed!\n");
  } 
  else {
    printf("...FAILED!\n");
        ++n_fails; // Increment number of failures
  }
  
  if (n_fails > 0) {
        printf("%d tests FAILED!\n", n_fails);
  }
  else {
        printf("All tests passed!\n");
  }

  return n_fails;
}

#endif
  