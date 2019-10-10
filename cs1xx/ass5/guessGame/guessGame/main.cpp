//Parham Davoodi
//cs111
/*
 generates a random number between 1 and 100 and asks the user to guess what the number is. If the user's guess is higher than the random number, the program should display “Too high, try again”. If the user’s guess is lower than the random number, the program should display “Too low, try again”. The program should use a loop that repeats until the user correctly guesses the random number.
*/


#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    
    //grab random number
    srand(time(0));
    int num;
    num = rand() % 100 + 1; // num gets some random number between 1 and 100
    //========================================================================
    //variables
    int guess;
        
    cout << "Guess a number between 1 and 100. Enter your guess: ";
    cin >> guess;
    do {
        if (num < guess) {
            cout << "Too high, try again." <<endl;
        }else if (num > guess) {
            cout << "Too low, try again." <<endl;
        }
        
        //ask for number again
        cout<<"Enter your guess: " ;
        cin>>guess;
        
    } while (guess != num);
    
    if (guess == num){
        cout<<"Your guess is right!"<<endl;
    }
    
    
    
    return 0;
}
