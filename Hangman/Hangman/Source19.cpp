#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

string getWords();
//Pre-condition:
//Post-condition:

int playGame(string MysteryWord);
//Pre-condition:
//Post-condition:


int main()
{
	int useranswer = 20;
	do
	{
		string MysteryWord = getWords();
		useranswer = playGame(MysteryWord);

	} while (useranswer == 1);
	
	cout << endl;
	cout << "Thank you for playing. " << endl;
	cout << endl;

return 0;
}

//Description:
string getWords()
{
	//Declare Local variables
	int count=0;
	string temp="";

	//Open up Stream
	fstream myfile;
	myfile.open("words.txt");

	//Logic for Reading how many strings are in the file
		while (myfile.is_open() && myfile.good())
		{
			while (myfile >> temp)
				count++;
		}
	
	//Declare Array size of # of strings in file	
	string myWords[20];

	//Close the stream
	myfile.close();

	//Re-open the stream
	myfile.open("words.txt");

	//for-loop that stores strings into Array called "myWords" 
		for (int i = 0; i < 20; i++)
		{
			myfile >> myWords[i];
		}

	//Create random int between 0-19 to select for string variable from Array myWords[]
	srand(time(NULL));
	int randomNum = rand() % (sizeof(myWords)/sizeof(myWords[0]));
	
	//Assign random number to index in array with strings read from the text file.
	string MysteryWord = myWords[randomNum];

//return MystoryWord which is a string randomnly selected from the mywords[] Array 
return MysteryWord;
}

//Description:
int playGame(string MysteryWord)
{
	//Declare local variables
	int playagain;
	bool usercondition = true;
	string UnknownWord(MysteryWord.length(), '*');

	//this while loop will control when the game is finished
	while (usercondition == true)
	{
		cout << MysteryWord;

		//Declare local variables
		char userguess;
		int wintemp;
		int win=0,loss=0;
		string tempUknownWord = "";
		tempUknownWord = UnknownWord;

		//Prompt the user to enter a guess
		cout << "(Guess) Enter a letter in word: " << UnknownWord<< '>';
		cin >> userguess;

		wintemp = win;
		
		for (int i =0; i < MysteryWord.length(); i++)
		{
			//Check if letter has already been guessed
			if (userguess == UnknownWord.at(i))
			{
				cout << userguess << " is already in the word" << endl;
				break;
			}

			//Checks if user guess is = to a character in the MysteryWord			
			else if (userguess == MysteryWord.at(i))
			{
				UnknownWord[i] = userguess;
				win++;
			}
		}

		//Check for not in word, add up loss variable


		//Check if User has completed the game by guessing all the unknown characters
		if (UnknownWord == MysteryWord)
		{
			char userinput;
			cout << endl;
			cout << "The word is " << MysteryWord << ". You missed " << loss << " times." << endl;
			cout << "Would you like to play again? (Y/(N)): ";
			cin >> userinput;
			
			if (userinput == 'Y' || userinput=='y')
			{
				playagain = 1;
				usercondition == false;
				cout << endl;
				break;
			}
			else
			{
				playagain = 0;
				usercondition == false;
				break;
			}
		}
	} //Ends while loop
return playagain;
}