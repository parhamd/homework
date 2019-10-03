//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//header
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include <string>
#include <iostream>
#include "Employee.h"
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



//Initialize
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int Employee::totalNumOfEmployees = 0;
int Employee::nextEmpId = 1000;
int Employee::nextOfficeNo = 10;
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Employee::Print() const
{
    cout << "*************************************************************"<<endl;
    cout << "********************Employee Information:" << endl;
    cout << "*************************************************************"<<endl;

    cout << "Employee name: "<< this->name << endl;
    cout << "Employee office number: " << this->officeNo << endl;
    cout << "Employee ID: "<< this->empId << endl;
    cout << "Employee department number: "<< this->deptNo << endl;
    cout << "Employee position: "<< this->empPosition << endl;
    cout << "Employee years of experience: "<<this->yearOfExp << endl;
    cout << "Employee salary: $"<< this->salary << endl;

    cout << "*************************************************************" << endl;
    cout << endl;

    cout << "Total number of employees: " << this->totalNumOfEmployees << endl;
    cout << "Next employee id: " << this->nextEmpId << endl;
    cout << "Next office number: "               << this->nextOfficeNo << endl;
    cout << "*************************************************************" << endl;
    cout << endl;
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Employee::GetInfo()
{
    cout<<"======================"<<endl;
    cout << "Enter the name: ";
    getline(cin, this->name);

    cout<< endl;
    cout << "E,e for Entry || P,p for Project leader || M,m for Manager || D,d for Director"<<endl;
    cout << "Enter the employee position: ";
    cin >> this->empPosition;
    cout << "Enter years of experience: ";
    cin >> this->yearOfExp;
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void SetSalary(Employee& employee)
{

    //++++++++++++++++++++++++
   if (employee.empPosition == 'E' || employee.empPosition == 'e') // Entry Level
   {
       if (employee.yearOfExp < 2)
       {
           employee.salary = 50000;
       }
       else
        {
            employee.salary = 55000;
        }
   }
   //++++++++++++++++++++++++

   //++++++++++++++++++++++++
   else if (employee.empPosition == 'P' || employee.empPosition == 'p') // Project leader
   {
       if (employee.yearOfExp < 4)
       {
           employee.salary = 60000;
       }
       else
        {
           employee.salary = 65000;
        }
   }
   //++++++++++++++++++++++++

   //++++++++++++++++++++++++
   else if (employee.empPosition == 'M' || employee.empPosition == 'm') // Manager
   {
       employee.salary = 70000;
   }
   //++++++++++++++++++++++++

   //++++++++++++++++++++++++
   else if (employee.empPosition == 'D' || employee.empPosition == 'd') // Director, could use an else, except that would cover invalid positions.
   {
       employee.salary = 80000;
   }
   //++++++++++++++++++++++++

}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
