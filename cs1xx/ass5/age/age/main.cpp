//Parham Davoodi oct 2019
/*
 description:
 program that will read an unknown number of ages. (0 is a valid age used for a baby.) The user will enter a negative number if there are no more ages to enter. The program will output the average age, the number of minors (less than 18), the number of adults (18 and above) and the youngest and oldest ages. If no ages were entered, display “No ages were entered” (see the last test case below).
 */

#include <iostream>
using namespace std;


int main() {
    //variables
    int age; //age entered
    int sum=0;//sum of ages
    double avg= 0;//average
    int minor=0;//minor number
    int adult=0;//adult number
    int oldest = 0;//oldest
    int youngest = 999;//youngest
    int num= 0; //counter
    //=================
    
    //get age
    cout << "Enter an age: ";
    cin >> age;
    //================
    
    
    //while true
    while (age>=0) {
        sum = sum + age;
        num ++;
        
        //counter for minor and adult
        if (age>17) {
            adult ++;
        }else {
            minor ++;
        }//===========================
        
        //oldest
        if (age>=oldest) {
            oldest = age;
        }//===========================
        
        //youngest
        if (age <= youngest) {
            youngest = age;
        }//===========================
        
        avg = sum/num;
        
        //next age
        cout << "Enter an age: ";
        cin>> age;
    }
    
    
    
    if (num == 0 ) {
        cout << "No ages were entered. "<<endl;
    }else {
        //print results
        cout << avg << " (average)"<<endl;
        cout << minor << " (minors)"<<endl;
        cout << adult << " (adults)"<<endl;
        cout << oldest << " (oldest)"<<endl;
        cout << youngest << " (youngest)"<<endl;
        cout << endl; //spacer to look nice and clean
    }
    
    
    return 0;
}
