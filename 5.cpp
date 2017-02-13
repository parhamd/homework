/* Homework Set 1, Problem 5 by Dillon Morse
 * -----------------------------------------
 * Write a program that stores the following values in five different
 * variables: 28, 32, 37, 24, and 33. The program should first calculate the
 * sum of these five variables and store the result in a seperate variable
 * named sum. Then, the program should divide the sum variable by 5 to get the
 * average. Display the average on the screen.
 */

#include<iostream>
using namespace std;

const int a = 28;
const int b = 32;
const int c = 37;
const int d = 24;
const int e = 33;

// It is simpler to take the size of the array as an argument than to try and
// find the number of variables in an array pointer.
// The name int_sum prevents conflicts with the variable, sum.
int int_sum(int nums[], int size) {
  // sum is declared as 0 so I can add to it in the for loop without any extra
  // code.
  int sum = 0;

  for(int i = 0; i < size; i++) {
    sum = sum + nums[i];
  }

  return sum;
}

int main() {
  int constants[6] = {a, b, c, d, e};
  // sizeof returns the size of the argument in bytes. So, I am dividing the
  // size of the array constants by the size of a constant stored in the array.
  int size = sizeof(constants) / sizeof(constants[0]);

  int sum = int_sum(constants, size);
  double average = sum / 5;

  cout << average << '\n';

  // Necessary to prevent warnings from the g++ compiler.
  // I'm not keeping the program running in a paused state because I am running
  // it from a CLI, so letting it close is most convenient.
  return 0;
}