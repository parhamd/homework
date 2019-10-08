/*
Parham Davoodi
Desc:
In this program we:
Create a program that will calculate the approximate value of e
*/
//=======header============
#include <iostream>
#include <cmath>
#include <iomanip>
//=======================
using namespace std;

int main()
{
    int n;

    cout << "Enter n: ";
    cin >> n;

    for (int a=0; a<n;a++)
    {
        for (int b=n; b>a;b--)
            {
                cout<< "0 ";
            }

        cout<<endl;
    }


    return 0;
}
