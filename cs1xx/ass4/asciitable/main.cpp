/*
Parham Davoodi
Desc:
In this program we use for loop to display characters
for the ascii value 35 to 126
    14per line
*/
//=======header============
#include <iostream>
#include <cmath>
#include <iomanip>
//=======================
using namespace std;

int main()
{
    //introduce counter
    int counter=0;
    //=================

    //=======for loop=========
    for (int a=35; a<127; a++)
    {
        cout<< setw(2)<<char(a);//print character
        counter ++; //counter for 14 in a row
        if(counter == 14)//skip line if counter reaches 14
        {
            counter = 0;//reset counter
            cout<<endl;//skipping line
        }
    }



    return 0;
}
