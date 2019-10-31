#ifndef DICTIONARY_H
#define DICTIONARY_H

//=============================================================================
#include <iostream>
#include<string>
#include<fstream>
#include<vector>
//=============================================================================

using namespace std;

//=============================================================================
class Dictionary
{
	private:
		const int maxWordsInDict;//Max word in dic
		const int maxWordsPerFile;//Max word / file
        int totalWordsInDict;//total words in dic
        int numOfWordsInFile[26];//num of words in file
		static  bool failure;//failure
		static	bool success;//success
	public:
		Dictionary();//constructor
		Dictionary(int dictMaxWords, int fileMaxWords);//constructor initialize
		bool AddAWord(string word);//adds a word
		bool DeleteAWord(string word);//deletes a word
		bool SearchForWord(string word);//search
		bool PrintAFileInDict(string filename);//print
		bool SpellChecking(string fileName);//spell check
		bool InsertWordsIntoDict(string fileName);//adding word into dictionary
		void ProcessTransactionFile();//reads user input
};
//=============================================================================


#endif
