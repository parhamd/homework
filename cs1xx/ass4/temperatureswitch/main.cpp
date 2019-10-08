/*
Parham Davoodi
Desc:
In this program we will convert C to F or F to C
using Switch.
*/
//=======header============
#include <iostream>
#include <cmath>
#include <iomanip>
//=======================
using namespace std;

int main()
{

    //========
    int tempenter;// temp entered in C
    char enter;
    double tempconv;//temp converted to F
    double tempconverted;// rounded
    //========

    cout << "Which temperature do you have? Enter F for Fahrenheit or C for Celsius?: ";
    cin>>enter;

    switch(enter)
    {
        case 'f':// lower f

        case 'F':// Capital F

            //============grab temp===============
            cout<<"Enter a temperature in Celsius: ";
            cin>>tempenter;
            //============calculations===============
            tempconv = (tempenter - 32.00)*5/9; //calculation

            // tempconverted = (int) (tempconv + 0.5); // to round this thing
            //==============printing===============
            cout<<tempenter<<" Fahrenheit = "<<fixed<<setprecision(2)<<tempconv<<" Celsius "<< endl; //outputs here
            cout<<" "<< endl;


            break;

        case 'c':// lower C

        case 'C': // capital C

            //============grab temp===============
            cout<<"Enter a temperature in Celsius: ";
            cin>>tempenter;
            //============calculations===============
            tempconv = tempenter * 9.00 / 5 + 32.00; //calculation

            // tempconverted = (int) (tempconv + 0.5); // to round this thing
            //==============printing===============
            cout<<tempenter<<" Celsius = "<<fixed<<setprecision(2)<<tempconv<<" Fahrenheit "<< endl; //outputs here
            cout<<" "<< endl;

            break;


        default:// for invalid
            cout << "Invalid choice"
            cout << endl;
            break;
    }

    return 0;
}
