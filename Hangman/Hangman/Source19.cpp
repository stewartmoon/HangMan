#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

string getWords();
int playGame(string MysteryWord);

int main()
{
	string MysteryWord = getWords();
	int useranswer = playGame(MysteryWord);

return 0;
}

string getWords()
{
	int count=0;
	string temp="";

	fstream myfile;
	myfile.open("words.txt");

		while (myfile.is_open() && myfile.good())
		{
			while (myfile >> temp)
				count++;
		}

	string myWords[20];

	myfile.close();
	myfile.open("words.txt");

		for (int i = 0; i < 20; i++)
		{
			myfile >> myWords[i];
		}

		srand(time(NULL));
		int randomNum = rand() % (sizeof(myWords)/sizeof(myWords[0]));
	
		string MysteryWord = myWords[randomNum];

return MysteryWord;
}

int playGame(string MysteryWord)
{
	int playagain;
	bool usercondition = true;
	string UnknownWord(MysteryWord.length(), '*');

	//Display MysteryWord
	while (usercondition)
	{
		cout << MysteryWord;
		char userguess;
		char userinput;
		int wintemp;
		int win=0,loss=0;
		string tempUknownWord = "";

		cout << "(Guess) Enter a letter in word: " << UnknownWord<< '>';
		cin >> userguess;

		wintemp = win;
		tempUknownWord = UnknownWord;

		
		for (int i =1; i < MysteryWord.length(); i++)
		{
		//Check if user guess is = to a character in the MysteryWord
			if (userguess == MysteryWord.at(i))
			{
				UnknownWord[i] = userguess;
				win++;
			}
		//Check if letter has already been guessed
			if (userguess == UnknownWord.at(i))
			{
				cout << userguess << " is already in the word" << endl;
				break;
			}
		}

		//Check for not in word		
        

		//Check if User has completed the game
		if (UnknownWord == MysteryWord)
		{
			cout << "The word is " << MysteryWord << ". You missed " << loss << " times." << endl;
			cout << "Would you like to play again? (Y/(N))";
			cin >> userinput;
			if (userinput == 'Y')
			{
				playagain = 1;
			}
			else
			{
				playagain = 0;
			}
		}
	}
return playagain;
}