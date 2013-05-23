// Name: Steven Kolln
// Description: Header file for the bowlingFunctions.cpp file.


#include <iostream>
#include <fstream>
#include <cctype>
#include <cmath>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

const int MAX_PLAYERS=10, MAX_GAMES=20;

//This method takes the two demensional array of all the players and their final score along
//with an int array of which player scores want to be seen. If 0 is entered it means all.
void viewScores(int[][MAX_GAMES], int, int);
//Starts a new game with x amount of players playing y amount of games.
void startNewGame(int, int);
//Takes a two demensional array where data will be stored, and the number of
//games to played and players playing.
void inputKeyboard(int, int);
//Takes a two demensional array where data will be stored, a file to read from and the number of
//games to played and players playing.
void inputFile(int, int);
//takes an output file to read from
void viewFinalScore(ifstream);
//Takes an array for where to store the data and a string representation of the file name to read from. Lastly, it takes an 
//int to denote which player to stores the games to.  The last int takes lowest and determines what to output if the user does not provide
// a large enough output file of games.
bool storeData(int[][MAX_GAMES], string, int, int&);
//Retrieves a valid int from input
int getValidInt();
// method to call startNewGame
void startGame(int&, int&);
//Determines whether to read from a file or not.
bool readFromFile();
//Converts and int to a string for easy concatination
string numberToString(int);
//Deletes a file with file name; will display output upon success.
void deleteFile(string);
//This method loops untill the user quits. It will ask the user if they want to view all scores or a specific individuals score and will
//continue untill the user enters a zero.
void lastMethod(int[][MAX_GAMES], int, int);
//Takes the array of scores, a player number and games he has played and prints them to the screen.
void viewPlayer(int [][MAX_GAMES], int, int);
//Asks the user if the want to use their own files  to read from.
bool ownFiles();
//Returns a string of the file the user would like to use.
string userFileMethod();