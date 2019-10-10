//Parham davoodi
//make a program to show Fibonacci numbers



#include <iostream>
using namespace std;

int main() {
    int n1=0;
    int n2=1;
    int n3;
    int n;
    

    
    do {
        cout<< "Enter the number of fibonacci numbers you want to see (N >= 3): ";
        cin>>n;
    } while (n<3);
    
    cout << "0 ";
    for (int i =1; i<n; i++) {
        cout<< n2 << " ";
        n3= n1+n2;
        n1=n2;
        n2=n3;
    }
    cout << endl;
 
    
    return 0;
}
