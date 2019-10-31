//=============================================================================
#include "Dictionary.h"
//=============================================================================

bool Dictionary::failure = false;
bool Dictionary::success = true;

//------------------------------------------------------------------
//Default constructor
//------------------------------------------------------------------
Dictionary::Dictionary():maxWordsInDict(10000), maxWordsPerFile(100), totalWordsInDict(0)

{
	for(int i = 0; i < 26; i++)
		numOfWordsInFile[i] = 0;
}
//------------------------------------------------------------------
//Parameterized constructor
//------------------------------------------------------------------
Dictionary::Dictionary(int dictMaxWords, int fileMaxWords):maxWordsInDict(dictMaxWords),maxWordsPerFile(fileMaxWords),totalWordsInDict(0)
{
	for(int i = 0; i < 26; i++)
		numOfWordsInFile[i] = 0;
}
//------------------------------------------------------------------

//------------------------------------------------------------------
//Add a word
//------------------------------------------------------------------
bool Dictionary::AddAWord(string word)
{
	bool searchResult = false;
	string fileName = "&.txt";
	fileName[0] = toupper(word[0]);
	searchResult = SearchForWord(word);

	if(searchResult == false)
		{
            return (Dictionary::failure);//exists already
		}

	ofstream fout;
	fout.open(fileName.data(), ios::app);

	if(totalWordsInDict++ > maxWordsInDict)
		return (Dictionary::failure);//Too many words in dictionary

	if(numOfWordsInFile[fileName[0]-'A']++ > maxWordsPerFile)
		return (Dictionary::failure);// overload with words fail

	word[0] = tolower(word[0]);

	fout << word << endl;
	totalWordsInDict++;
	numOfWordsInFile[fileName[0]-'A']++;
	fout.close();
	return (Dictionary::success);
}
//------------------------------------------------------------------


//------------------------------------------------------------------
//delete using a vector
//------------------------------------------------------------------
bool Dictionary::DeleteAWord(string word)//takes string of individual word to be deleted
{
	bool searchResult = false;
	string currword;
	string fileName = "&.txt";
	fileName[0] = toupper(word[0]);
	searchResult = SearchForWord(word);//searches for word

	if(searchResult == true)
		return (Dictionary::failure);

	fstream fin;
	fin.open(fileName.data());

	vector <string> hold;

	while(fin >> currword)
		hold.push_back(currword);//store file in vector

	for(int i = 0; i < hold.size(); i++)
	{
		if(hold[i] == word)//?word into vector
		{
			hold.erase(hold.begin()+i);
			totalWordsInDict--;
			numOfWordsInFile[fileName[0]-'A']--;
			for(int a = 0; a < hold.size(); a++)
				fin << hold[a];
			fin.close();
			return(Dictionary::success);
		}
	}
}
//------------------------------------------------------------------



//------------------------------------------------------------------
//Search for a word in the dictionary
//------------------------------------------------------------------
bool Dictionary::SearchForWord(string word)
{
	string fileName = "&.txt";
	string currword;
	fileName[0] = toupper(word[0]);
	ifstream fin;
	fin.open(fileName.data());

	while(fin >> currword)//currword hold the current word
	{
		if(word == currword)
			return (Dictionary::failure);
	}
	return (Dictionary::success);
}



//------------------------------------------------------------------
//print to dictionary
//------------------------------------------------------------------
bool Dictionary::PrintAFileInDict(string fileName)
{
	string printWord; //holder of a word to print
	int wordCount = 0;
	ifstream fin;
	fin.open(fileName.data());

	if(!fin)
		return (Dictionary::failure);

	cout << endl;
	while (fin >> printWord)
	{
		if(wordCount == 5)// insturctor asked to to 5 words /line
		{
			wordCount = 1;
			cout << endl << printWord << " ";
		}
		else
		{
			cout << printWord << " ";
			wordCount++;
		}
	}
	cout << endl;
	return (Dictionary::success);
}

//------------------------------------------------------------------
//spell check
//------------------------------------------------------------------
bool Dictionary::SpellChecking(string fileName)
{
	bool searchResult = false;
	string currword;
	ifstream fin;
	fin.open(fileName.data());

	if(!fin)
		return (Dictionary::failure);
	cout << "\nThe following words are spelled incorrectly:\n";
	while (fin >> currword)
	{
		for(int i = 0; i < currword.size(); i++)
			currword[i] = tolower(currword[i]);
		searchResult = SearchForWord(currword);
		if(searchResult == true)
			cout << currword << " ";
	}
	cout << endl;
	return (Dictionary::success);
}


//------------------------------------------------------------------
//insert words into dictionary
//------------------------------------------------------------------
bool Dictionary::InsertWordsIntoDict(string fileName)
{
	string currword;
	ifstream fin;
	fin.open(fileName.data());

	if(!fin)
		return (Dictionary::failure);

	while (fin >> currword)
	{
		for(int i = 0; i < currword.size(); i++)
			currword[i] = tolower(currword[i]);
		AddAWord(currword);
	}
	return (Dictionary::success);
}

//------------------------------------------------------------------
//open transfile
//------------------------------------------------------------------
void Dictionary::ProcessTransactionFile()
{
	string fileName, command, data;
	bool result = false;
	cout << "Please enter the name of the transaction file:";
	getline(cin, fileName);

	cout << endl;

	ifstream fin;
	fin.open(fileName.data());

	//==============
	//If file exists
	//==============
	if(!fin)
	{
		cout << "That transaction file does not exist!" << endl;
		return;
	}

	while(fin >> command >> data)
	{
		if(command == "AddW")
		{
			result = AddAWord(data);
			if(result == false)
				cout << "The word " << data << " was not added successfully!" << endl;
			else
				cout << "The word " << data << " was added successfully!" << endl;
		}
		else if(command == "DeleteW")
		{
			result = DeleteAWord(data);
			if(result == false)
				cout << "The word " << data << " was not deleted successfully!" << endl;
			else
				cout << "The word " << data << " was deleted successfully!" << endl;
		}
		else if(command == "SearchW")
		{
			result = SearchForWord(data);
			if(result == true)
				cout << "The word " << data << " was not found!" << endl;
			else
				cout << "The word " << data << " was found!" << endl;
		}
		else if(command == "PrintF")
		{
			cout << "Printing file " << data  << endl;
			result = PrintAFileInDict(data);
			if(result == false)
				cout << "The file " << data << " could not be opened!" << endl;
			else
				cout << "\nThe file " << data << " was printed!\n" << endl;
		}
		else if(command == "SpellCheck")
		{
			result = SpellChecking(data);
			if(result == false)
				cout << "The file " << data << " could not be opened!" << endl;
			else
				cout << "\nThe file " << data << " was spellchecked successfully!" << endl;
		}
		else if(command == "InsertF")
		{
			result = InsertWordsIntoDict(data);
			if(result == false)
				cout << "The file " << data << " could not be opened!" << endl;
			else
				cout << "The file " << data << " was inserted successfully!" << endl;
		}
		else
		{
			cout << "Invalid command in transaction file!" << endl
			     << "Command was " << command << endl;
		}
	}
}
