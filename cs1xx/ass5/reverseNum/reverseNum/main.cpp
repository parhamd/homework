//Parham Davoodi
/*
 program that will ask for a non-negative integer number (zero or positive value) and show all the digits backwards.
 
 */

#include <iostream>
using namespace std;



int main() {
    int num; //grab num
    int remainder;//remainder
    int reversedNumber=0;//reversednum
    
    
    cout << "Enter a non-negative number: ";
    cin >>num;
    
    //grab number >= 0
    do {
        if (num<0) {
            cout << "The number is invalid. Enter a number again: ";
            cin >>num;
        }
    } while (num <0);
    //===============================
    
    if (num == 0){
        cout << num<<endl;
    }else {
        
        while(num != 0)
        {
            remainder = num%10;
            reversedNumber = reversedNumber*10 + remainder;
            num /= 10;
        }
        cout << "Reversed Number = " << reversedNumber<< endl;
    
    }//end else != 0
        
    return 0;
}
