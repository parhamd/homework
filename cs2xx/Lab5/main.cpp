//+++++++++++++++++++++++++++++
#include <iostream>
#include <string>
#include "Employee.h"
//+++++++++++++++++++++++++++++
using namespace std;
//+++++++++++++++++++++++++++++




int main()
{
   Employee emp1;
   emp1.Print();
   Employee emp2("unknown", 10, '?', 0);
   emp2.GetInfo();
   cout << endl;
   SetSalary(emp2);
   emp2.Print();
   return 0;
}
