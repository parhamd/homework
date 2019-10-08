/*
Parham Davoodi
Desc:
In this program we:
calculates how much a person would earn over a period of time if his or her salary is one penny
the first day and two pennies the second day, and continues to double each day
*/
//=======header============
#include <iostream>
#include <cmath>
#include <iomanip>
//=======================
using namespace std;


int main()
{
    int days;
    double total =0;
    double pay =1;

    cout << "Enter the number of days you worked: ";
    cin >> days;
    cout << endl;


    //==========set rule for day be +0 ======================
    if (days < 1)
    {
        cout << days << "is invalid. Thank you for using the system.";
    }
    //=======if conditions are good start here==================
    else if (days >0)
    {
        //print top table===========================
        cout << setw(10)<<right<<"Days" << setw(15)<< "Pay" << endl;
        cout << "-------------------------"<<endl;
        //=====================================

        //printing actual number table ==================
        for (int counter = 1; counter < days+1; counter ++)
        {
            cout << setw(10)<<right<< counter << setw(15)<< fixed<<setprecision(2)<<pay/100<<endl;

            //==========calculations============
            total = total +pay;
            pay = (pay *2);
            //==============================

        }

        //total print ======================================
        cout << "-------------------------"<<endl;
        cout << setw(10)<<right<<"Total" << setw(15)<< total/100 << endl;
    }


    return 0;
}
