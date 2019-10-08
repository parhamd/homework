/*
Parham Davoodi
Desc:
In this program we:
The user will enter a number (>= 1) into n then your program will show 1 star on the first line, 2 stars on
the second line, ….. n stars on the nth line as shown below
*/
//=======header============
#include <iostream>
#include <cmath>
#include <iomanip>
//=======================
using namespace std;

int main()
{
    int num; //input

    //==========grab user input=====
    cout<< "Enter the number of rows: ";
    cin>>num;
    //=========================


    //=====conditions met? if so go in===
    if (num>=1)
    {
        // print 10x  use as row
        for (int i=1;i<num+1; i++)
        {
            //print 10x 9x 8x 7x ...1x
            for (int iii=num; iii>i;iii--)
            {
                cout<< " ";
            }
            //print 1x 2x 3x... 10x
            for(int ii=0;ii<i;ii++)
            {
                cout << "*";
            }


        cout << endl;//jump line

        }


    }
    //=========if conditions are not met============
    else
    {
        cout << "This program works for n>=1 only";
    }
    //=====================================



    return 0;
}
