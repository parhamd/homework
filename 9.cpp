/* Homework Set 1 Problem 9 by Dillon Morse
 * ----------------------------------------
 * You have been given a job as a programmer on a Cyborg supercomputer. In
 * order to accomplish some calculations, you need to know how many bytes the
 * following data types use: char, int, float, and double. You do not have any
 * manuals, so you can't look this information up. Write a C++ program that
 * will determine the amount of memory used by these types and display the
 * information on the screen.
 */

#include<iostream>
using namespace std;

int main() {
  char character;
  int integer;
  float single_precision_floating_point;
  double double_precision_floating_point;

  string out;

  // sizeof returns the size of a variable in bytes.
  // to_string was added in C++ 11 and is used to convert variables to strings.
  out = to_string(sizeof(character)) + ", " + to_string(sizeof(integer)) +
        ", " + to_string(sizeof(single_precision_floating_point)) + ", " +
        to_string(sizeof(double_precision_floating_point));

  cout << out << '\n';

  // Necessary to prevent warnings from the g++ compiler.
  // I'm not keeping the program running in a paused state because I am running
  // it from a CLI, so letting it close is most convenient.
  return 0;
}