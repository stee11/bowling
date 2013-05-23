// Name: Steven Kolln
// Description: Driver for the bowling program. Users enter the players and games to play and whether to read from a file or not.
// Then users can retrieve the data from a two demensional array at the end.

#include "bowlingFunctions.h"

using namespace std;

int main()
{
	bool file, userFile=false;
	string usersFile;
	//Can't be bigger than [20][10]
	int scores[MAX_PLAYERS][MAX_GAMES];
	int players, games, lowest;
	string fileName;
	//This method passes a reference to players and games and gives them a value
	startGame(players, games);
	//lowest eventually checks for use input file what the least ammount of games they use are. here just in case the user gives a bad input file.
	lowest=games;
	//returns a bool to whether or not user input will be used or keyboard input
	file=readFromFile();
	if (file)
	{
		if (ownFiles())
		{
			bool user;
			userFile=true;
			usersFile=userFileMethod();
			for (int count=0;count<players;count++)
			{
				fileName=usersFile+numberToString(count+1)+".txt";
				user=storeData(scores, fileName, count, lowest);
				if (user==false)
					userFile=false;
			}
			
		}
		if (!userFile)
			inputFile(players, games);
	}
	else
	{
		inputKeyboard(players, games);
		cout << endl;
	}
	//Reads the files and stores the file data into the array.
	if (!userFile)
	{
		for (int count=0;count<players;count++)
		{
			fileName="player"+numberToString(count+1)+"scores.txt";
			storeData(scores, fileName, count, lowest);
		}
	}
	//This method loops until a 0 is entered and gives the user different options to view the scores.
	lastMethod(scores, players, lowest);
	cout << endl << endl;
	//Deletes all the files that were created before.
	if (!userFile)
	{
		for (int count=1; count<=players;count++)
		{
			string fileName="player"+numberToString(count)+"scores.txt";
			deleteFile(fileName);
		}
	}
	else
		cout  << "Will leave user files in directory and not delete them" << endl << endl;
	cout << endl << endl << "Program terminating. Have a good day! :)" << endl;
	return 0;
}
