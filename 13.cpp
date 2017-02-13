/* Homework Set 1 Problem 13 by Dillon Morse
 * -----------------------------------------
 * An electronics company sells circuit boards at a 40 percent profit. Write a
 * program that will calculate the selling price of a circuit board that costs
 * $12.67. Display the result on the screen.
 */

#include<iostream>
#include<cmath>
using namespace std;

string price(double cost) {
  double selling_price = cost * 1.4;
  string str_price;

  str_price = "$" + to_string(round(selling_price * 100) / 100);
  // This is necessary to remove trailing zeros from the string resulting from
  // the above statement.
  str_price.erase(str_price.find_last_not_of('0') + 1, string::npos);
  
  return str_price;
}

int main() {
  double cost = 12.67;

  cout << price(cost) << '\n';

  // Necessary to prevent warnings from the g++ compiler.
  // I'm not keeping the program running in a paused state because I am running
  // it from a CLI, so letting it close is most convenient.
  return 0;
}