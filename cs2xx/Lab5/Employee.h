//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//header
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include <string>
#include <iostream>
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
using namespace std;
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
class Employee
{
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
   private:
       string name;
       const long officeNo;
       const long empId;
       int deptNo;
       char empPosition; // 'E': entry level, 'M': manager, 'D': Director, 'P': Project_leader
       int yearOfExp;
       double salary;
       static int totalNumOfEmployees;
       static int nextEmpId;
       static int nextOfficeNo;
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
   public:
       Employee() : officeNo(nextOfficeNo++), empId(nextEmpId++)
       {
           name = "Unknown";
           deptNo = 0;
           empPosition = 'E';
           yearOfExp = 0;
           salary = 0.0;
           totalNumOfEmployees++;
       }

       ~Employee() { totalNumOfEmployees--; };

      Employee(const string& theName, int theDeptNo, char theEmpPosition, int theYearOfExp) : officeNo(nextOfficeNo++), empId(nextEmpId++)
       {
           this->name = theName;
           this->deptNo = theDeptNo;
           this->empPosition = theEmpPosition;
           this->yearOfExp = theYearOfExp;
           this->salary = 0.0;
           totalNumOfEmployees++;
       }

       //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
       void Print() const;
       void GetInfo();
       friend void SetSalary(Employee&);
       //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

};
