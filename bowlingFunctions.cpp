// Name: Steven Kolln
// Description: Functions definitions for the bowlingDriver.cpp file

#include "bowlingFunctions.h"

using namespace std;

//General notes: Anytime the stringstream is used is for the help of its str() method which helps makes strings easier to form.
//Method descriptions are located before each method.


//This method takes the two demensional array of all the players and their final score along
//with an int array of which player scores want to be seen. If 0 is entered it means all.
void viewScores(int scores[][MAX_GAMES], int players, int games)
{
	for (int i=0;i<players;i++)
	{
		cout << endl;
		cout << "Player " << (i+1) << ":\t";
		for (int a=0;a<games;a++)
		{
			cout << scores[i][a] << "\t";
		}
	}
	cout << endl << endl;
}
//Reads data from an input file and stores it in a two demensional array.
bool storeData(int games[][MAX_GAMES], string fileName, int playerNum, int& lowest)
{
	int gameNumCount=0;
	ifstream stream (fileName.c_str());
	if (stream.is_open())
	{
		cout << "File " << fileName << " was succesfully added to the list!" << endl;
		while (!stream.eof())
		{
			int i;
			stream >> games[playerNum][gameNumCount];
			gameNumCount++;
		}
	if (gameNumCount<lowest)
		lowest=gameNumCount;
	
	return true;
	}
	else
	{
		cout << endl << "Could not open " << fileName.c_str();
		return false;
	}
}
//Takes a two demensional array where data will be stored, and the number of
//games to played and players playing.
void inputKeyboard(int numPlayers, int numGames)
{
	string fileName;
	cout << "You will be entering scores from the keyboard" << endl << endl;
	//for loop for each file depending on number of players playing
	for (int count=1;count<=numPlayers;count++)
	{
		ofstream outputFile;
		fileName="player"+numberToString(count)+"scores.txt";
		//opens stream
		outputFile.open(fileName.c_str());
		cout << "Please enter a score between 0 and 300 for each game played followed by hitting enter. For player "<<count<<" please enter "<<numGames<<" scores please." << endl <<endl;
		//for loop for number of numbers to to be typed in based on the number of games to be played
		for (int gameNumber=0;gameNumber<numGames;gameNumber++)
		{
			bool done=false;
			while(!done)
			{
				int input=getValidInt();
				if (input>-1&&input<301)
				{
					outputFile << input << "\n";
					done=true;
				}
				else
					cout << "Please enter a number between 0 and 300" << endl << endl;
			}
		}
	}
}
//Takes a two demensional array where data will be stored, a file to read from and the number of
//games to played and players playing.
void inputFile(int players, int games)
{
	//creates random seed.
	srand ( time(NULL) );
	cout <<endl <<endl << "You will be reading from a randomly generated file" << endl << endl;
	string fileName;
	//for each file
	for (int count=1;count<=players;count++)
	{
		ofstream outputFile;
		fileName="player"+numberToString(count)+"scores.txt";
		outputFile.open(fileName.c_str());
		//generate random number for each game for that player
		for (int gameNum=0;gameNum<games;gameNum++)
		{
			if (games-gameNum!=1)
				outputFile << rand()%300 << "\n";
			else
				outputFile << rand()%300;
		}
	}
}
//Retrieves a valid int from input
int getValidInt()
{
	bool tryAgain = true;
	int value;
	
    while (tryAgain) 
	{
		cin >> value;
		if (cin.fail()) 
		{
			cout << "*** Invalid Input *** Please enter a int value: ";
			cin.clear();
			cin.ignore (1000, '\n');
	    }
		else
			tryAgain = false;
	}
	return value;
}
// method to call startNewGame. Passes players and games by reference. Makes some grammar checks at the end.
void startGame(int& players, int& games)
{
	cout << "How many players will playing with you today?" << endl;
	bool valid=false;
	while (!valid)
	{
		players=getValidInt();
		if (players>0&&players<=MAX_PLAYERS)
			valid=true;
		else
			cout << "Please enter a number between 0 and " << MAX_PLAYERS << "." << endl;
	}
	valid=false;
	cout << "How many games would you like to play?" << endl;
	while (!valid)
	{
		games=getValidInt();
		if (games>0&&games<=MAX_GAMES)
			valid=true;
		else
			cout << "Please enter a number between 0 and " << MAX_GAMES << "." << endl;
	}
	if (games==1)
	{
		if (players==1)
			cout << endl << endl << "You will be playing " << games << " game with " << players << " player. Get some friends :D" << endl << endl;
		else
			cout << endl << endl << "You will be playing " << games << " game with " << players << " players." << endl << endl;
	}
	else
	{
		if (players==1)
			cout << endl << endl << "You will be playing " << games << " games with " << players << " player. Get some friends :D" << endl << endl;
		else
			cout << endl << endl << "You will be playing " << games << " games with " << players << " players." << endl << endl;
	}
		
}
//Determines whether to read from a file or not.
bool readFromFile()
{
	cout << "Would you like to enter inputs yourself or read from a file. Press f for file or any other key for input yourself." << endl;
	string input;
	cin.ignore();
	getline(cin, input);
	//the first character is only used here
	char answer=toupper(input.substr(0,1).c_str()[0]);
	if (answer=='F')
		return true;
	return false;
}
//Converts and int to a string for easy concatination
string numberToString(int n)
{
	string s;
	ostringstream stream;
	stream << n;
	s=stream.str();
	return s;
}
//Deletes a file with string name s. Will inform you if there is an error.
void deleteFile(string s)
{
	stringstream stream;
	string output;
	if (remove(s.c_str())!=0)
	{
		stream << "File " << s << "had an error";
		output=stream.str();
		perror(output.c_str());
	}
	else
	{
		stream << "File " << s << " was successfully deleted!";
		output=stream.str();
		puts(output.c_str());
	}
}
//This method loops untill the user quits. It will ask the user if they want to view all scores or a specific individuals score and will
//continue untill the user enters a zero.
void lastMethod(int scores[][MAX_GAMES], int players, int games)
{
	bool done=false;
	int choice;
	cout << "File input and output successfully completed!" << endl << endl;
	while (!done)
	{
		cout << "Press 0 to exit, 1 to view all scores of all players or press 2 to view a specific players score." << endl << endl; 
		choice=getValidInt();
		switch (choice)
		{
			case 0:
			{
				done=true;
				break;
			}
			case 1:
			{
				viewScores(scores, players, games);
				cout <<"SUCCESS!" << endl << endl;
				break;
			}
			case 2:
			{
				bool valid=false;
				cout << "Please enter a player number between 1 and " << players << "." << endl << endl;
				while (!valid)
				{
					choice=getValidInt();
					if (choice > 0 && choice <= players)
						valid=true;
					else
						cout << "Your input was not valid. Please enter a number between 1 and " << players << "." << endl << endl;
				}
				viewPlayer(scores, choice, games);
				cout << endl << endl << "SUCCESS!" << endl << endl;
				break;
			}
			default:
			{
				cout << "You did not enter a 0, 1, or a 2." << endl << endl;
				break;
			}
		}
	}
}
//Takes the array of scores, a player number and games he has played and prints them to the screen.
void viewPlayer(int scores[][MAX_GAMES], int players, int games)
{
	cout << "Player " << (players) << ":\t";
	for (int a=0;a<games;a++)
	{
		cout << scores[players-1][a] << "\t";
	}
}
////Asks the user if the want to use their own files  to read from.
bool ownFiles()
{
	cout << "Would you like to enter your own files to read from? Press y for yes and anything else for no." << endl << endl;
	string input;
	cin >> input;
	//the first character is only used here
	char answer=toupper(input.substr(0,1).c_str()[0]);
	if (answer=='Y')
		return true;
	return false;
}
//Returns a string of the file the user would like to use.
string userFileMethod()
{
	cout << endl << "What is the name of the file(s) you would like to use? Give the name of the file(s) without number or extension. Refer to readme with questions." << endl << endl;
	string input;
	cin >> input;
	cout << endl;
	return input;
}
