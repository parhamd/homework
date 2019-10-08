//============================================================
//Parham Davoodi
//In this program we enc or dec from a file and save back to a file
//using ROT or crypto
//Make sure to name the output and input file
//============================================================
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;
//============================================================


//============================================================
//Declare the Enc or Dec class
//============================================================
class EncorDec //Class for encryption or decryption
{
public:
    EncorDec() {};
    string keyFile; // use key
    vector<string> originalFile; //use to read file
    string filetoString(string filename); //copy data to string.
    vector<string> filetoVector(string filename); //copy to vector.
    void vectortoFile(const vector<string>& V, string filename); //Vector to file
    void printVector(const vector<string> V); //Method for displaying a vector.
    void EncryptROT(); //Encrypts ROT method.
    void DecryptROT(); //Decrypts ROT method.
    void EncryptCrypto(); //Encrypts cryptogram method.
    void DecryptCrypto(); //Decrypts cryptogram method.
};
//============================================================

//============================================================
//Copy file sentences into a vector
//============================================================
vector<string> EncorDec::filetoVector(string filename)
{
   ifstream fin;
   fin.open(filename.data());
   string word;
   if (!fin)
   {
       cout << "!!! File error "<< endl;
       exit(1);
   }
   else
   {
       while (fin >> word)
           originalFile.push_back(word);
       fin.close();
   }
   return originalFile;
}
//=========================================================

//============================================================
// vector to file : used to save back to the file and name it as professor request
//============================================================
void EncorDec::vectortoFile(const vector<string>& V, string filename)
{
   ofstream fout;
   fout.open(filename.data()); //Read a vector and save it to a file.
   string word;
   if (!fout)
   {
       cout << "!!!! Error openning file"<< endl;
       exit(1);
   }
   else
   {
       for (int i = 0; i<V.size(); i++) //read back to file to save
       {
           word = V[i];
           fout << word << " ";
       }
       fout.close();
   }
   return;
}
//=========================================================


//============================================================
//Grab Key
//============================================================
string EncorDec::filetoString(string filename)
{
   ifstream fin;
   fin.open(filename.data());
   string word;
   if (!fin)
   {
       cout << "!! File Error !! "<< endl;
       exit(1);
   }
   else
   {
       while (!fin.eof())
           keyFile.push_back(fin.get());
       fin.close();
   }
   return keyFile;
}
//===========================================================

//========================================================
void EncorDec::printVector(const vector<string> V)
{
   for (int i = 0; i<V.size(); i++) //Output vector V for confirmation.
       cout << V[i] << " ";
   cout << endl;
}
//=========================================================


//============================================================
//Enc using ROT
//=========================================================
void EncorDec::EncryptROT()
{
    int rot = 0;
    string filename = "Original.txt";
    string save = "EncryptRot.txt";
    
    cout << "\nEnter ROT number: ";
    cin >> rot;
    cout << endl;
    
    vector<string> V = filetoVector(filename); //Load file from user input into vector V.
    
    //ENC Vector
    vector<string> encVec;


    //Store
    for (int i = 0; i<V.size(); i++)
    {
       string word = V[i];
       for (int qq = 0; qq<word.size(); qq++) //Read word 1by1.
       {
           int value = word[qq];
           if (value>96 && value<123) //Encrypt lowercase.
           {
               value += rot;
               if (value>122)
                   word[qq] = value - 26;
               else
                   word[qq] = value;
           }
           else if (value>64 && value<91) //Encrypt uppercase.
           {
               value += rot;
               if (value>90)
                   word[qq] = value - 26;
               else
                   word[qq] = value;
           }
           else
           {
               word[qq] = value;//defualt dont touch if its symbol and stuff
           }
       }
        
       string encryptWord = word; //Word >>>> enc word
       encVec.push_back(encryptWord); //Store string encryptWord in vector encVec.
    
    }
    vectortoFile(encVec, save); //save
    printVector(encVec); //print
    return;
}
//============================================================

//============================================================
//Dec using ROT
//============================================================
void EncorDec::DecryptROT() //Decrypt ROT method.
{

    int rot = 0;
    string filename = "EncryptRot.txt";
    string save = "DecryptRot.txt";
    cout << "\nEnter ROT number: "; //Ask the user for input.
    cin >> rot;
    cout << endl;
    vector<string> V = filetoVector(filename); //file to vector
    vector<string> decVec; //decVector
    
    //+++++++++++++++++++++++++++++++++++++++
    //We do the same but opposite as ENCCC
    //+++++++++++++++++++++++++++++++++++++++
    for (int qq = 0; qq<V.size(); qq++)
    {
       string word = V[qq];
       for (int qq = 0; qq<word.size(); qq++)
       {
           int value = word[qq];
           if (value>96 && value<123)
           {
               value -= rot;
               if (value<97)
                   word[qq] = value + 26;
               else
                   word[qq] = value;
           }
           else if (value>64 && value<91)
           {
               value -= rot;
               if (value<65)
                   word[qq] = value + 26;
               else
                   word[qq] = value;
           }
           else
           {
               word[qq] = value;
           }
       }
        
        
       string decryptWord = word;
       decVec.push_back(decryptWord);
    }
    
    vectortoFile(decVec, save);
    printVector(decVec);
    return;
}
//============================================================


//============================================================
//Enc using Crypto
//============================================================
void EncorDec::EncryptCrypto()
{
   cout << endl;
   string filename = "Original.txt";
   string key = "key.txt";
   string save = "EncryptCrypto.txt";
   string key2 = filetoString(key);
   vector<string> V = filetoVector(filename); //file to vector
   vector<string> encVec;
    
    // again do the same thing
    
   for (int qq = 0; qq<V.size(); qq++)
   {
       string word = V[qq];
       for (int qq = 0; qq<word.length(); qq++)
       {
           int value = word[qq];
           if (value>96 && value<123) //Encrypt lowercase.
           {
               char value2 = key2.at(value - 97);
               word[qq] = value2;
           }
           else if (value>64 && value<91) //Encrypt uppercase.
           {
               char value2 = key2.at(value - 65);
               word[qq] = value2 - 32;
           }
           else
           {
               word[qq] = value;
           }
       }
       string encryptWord = word;
       encVec.push_back(encryptWord);

   }
   vectortoFile(encVec, save);//saving
   printVector(encVec);//print to make sure
   return;
}
//============================================================


//============================================================
//Dec using Crypto
//============================================================
void EncorDec::DecryptCrypto()
{

    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    
    
    string filename = "EncryptCrypto.txt";//input
    string save = "DecryptCrypto.txt";//save file name
    //key
    string key = "key.txt";//key file location
    string key2 = filetoString(key);
    //key end
    
    vector<string> V = filetoVector(filename);//file to vector and then read to it
    vector<string> decVec;

   for (int i = 0; i<V.size(); i++)
   {
       string word = V[i];
       for (int qq = 0; qq<word.length(); qq++)
       {
           int value = word[qq];
           if (value>96 && value<123) //Decrypt lowercase.
           {
               char value = word[qq];
               int value2 = key2.find(value, 0);
               word[qq] = value2 + 97;
           }
           else if (value>64 && value<91) //Decrypt uppercase.
           {
               char value = word[qq] + 32;
               int value2 = key2.find(value, 0);
               word[qq] = value2 + 65;
           }

           else
           {
               word[qq] = value;
           }

       }

       string decryptWord = word;
       decVec.push_back(decryptWord);
   }

   vectortoFile(decVec, save);
   printVector(decVec);
   return;
}
//=================================================================


//Declare functions.
void menuLoop();
void menuEncrypt();
void menuDecrypt();


//=================================================================
//main function
//=================================================================
int main()
{
    cout << "====================================================================="<< endl;
    cout << "Encryption and Decryption Program"<<endl;
    cout << "====================================================================="<< endl;
    menuLoop(); //Begin the program loop
    cout << "====================================================================="<< endl;
    cout << "Thank you for using"<<endl;
    cout << "====================================================================="<< endl;
    return 0;
}
//============================================================



//============================================================
//Main loop of menu
//============================================================
void menuLoop()
{
   bool exit = false; //keeps program open.
   int choice = 0; //introduce option.
    while (exit == false) //Begin menu selection loop.
    {

       cout << "\n(1) Encrypt Data" << "\n(2) Decrypt Data" << "\n(3) Exit"<<endl;
       cout << "option: ";
       cin >> choice;
       
       
       switch (choice)
       {
       case 1:
       {
           menuEncrypt();
           break;
       }
       case 2:
       {
           menuDecrypt();
           break;
       }
       case 3: //EXIT
       {
           exit = true;
           break;
       }
       default:
       {
           cout << "\ninvalid" << endl;
           break;
       }
       }
    }
    return;

}
//============================================================


//============================================================
//Enc Menu
//============================================================
void menuEncrypt()
{

    EncorDec Encrypt;
    int choice = 0;
    cout<<endl;
    cout<<endl;
    cout<< "How to Encrypt?"<<endl;
    cout<< "-------------------------"<<endl;
    cout << "\n(1) ROT" << "\n(2) Cryptogram" << "\n(3) Cancel"<<endl;
    cout << "option: ";
    cin >> choice;
   switch (choice)
   {
   case 1:
    {
       Encrypt.EncryptROT();
       break;
    }
   case 2:
       
    {
       Encrypt.EncryptCrypto();
       break;
    }
   case 3:
    {
       break;
        
    }

   default:
   {
       cout << "\nInvalid selection, please try again." << endl;
       break;
   }

   }
   return;
}
//============================================================

//============================================================
//Dec Menu
//============================================================
void menuDecrypt()
{
    EncorDec Decrypt;
    int choice = 0;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "How to Decrypt?"<<endl;
    cout << "---------------------"<<endl;
    cout << "\n(1) ROT" << "\n(2) Cryptogram"<< "\n(3) Cancel"<<endl;
    cout << "option: ";
    cin >> choice;

   switch (choice)
   {
   case 1:
   {
       Decrypt.DecryptROT();
       break;
   }

   case 2:
   {
       Decrypt.DecryptCrypto();
       break;
   }

   case 3:
   {
       break;
   }

   default:
   {
       cout << "\tInvalid " << endl;
       break;
   }

   }
   return;
}
//=========================================================
