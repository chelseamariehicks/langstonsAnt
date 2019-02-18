/***************************************************************************
** Author:          Chelsea Hicks
** Date:            1/17/19
** Description:     The source code file for the main simulation of
**                  Langston's Ant. All functions will be called here.
***************************************************************************/

#include <iostream>
#include <iomanip>
#include "menu.hpp"

using std::cout;
using std::cin;
using std::endl;

int main()
{
	//Calls menu to get user choice to start or quit 
	int choice = menu();
	
	//If user wants to start Langston's ant
	while (choice == 1)
	{
		//variables to hold user input
		int rows, cols, steps, rowStart, colStart;
		
		/*Messages to user to get input for rows, columns, steps,
		and starting position. */
		cout << "Let's begin. How many rows do you want on the board?" << endl;
		cout << "Please enter a number between 1 and 500." << endl;
		cin >> rows;
		
		//Checks that user input is a valid integer between 1-500
		while (!cin.good() || cin.get() != '\n' ||rows > 500 || rows < 1)
		{
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Please enter a number between 1 and 500." << endl;
			cin >> rows;
		}
		
		cout << "How many columns do you want on the board?" << endl;
		cout << "Please enter a number between 1 and 500." << endl;
		cin >> cols;
		
		//Checks that user input is a valid integer between 1-500
		while (!cin.good() || cin.get() != '\n' || cols > 500 || cols < 1)
		{
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Please enter a number between 1 and 500." << endl;
			cin >> cols;
		}

		cout << "How many steps do you want to run in the simulation?" << endl;
		cin >> steps;
		
		//Checks that user input is a valid integer
		while (!cin.good() || cin.get() != '\n' || steps < 1)
		{
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Please enter the number of steps." << endl;
			cin >> steps;
		}
		
		cout << "What row do you want the ant to start on?" << endl;
		cin >> rowStart;
		
		//Checks that user input is a valid integer on the board
		while (!cin.good() || cin.get() != '\n' || rowStart > rows || rowStart < 0)
		{
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Please enter a starting row less than or equal ";
			cout << "to the number of rows on the board." << endl;
			cin >> rowStart;
		}

		cout << "What column do you want to ant to start on?" << endl;
		cin >> colStart;
		
		//Checks that user input is a valid integer on the board
		while (!cin.good() || cin.get() != '\n' || colStart > cols || colStart < 0)
		{
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Please enter a starting column less than or equal ";
			cout << "to the number of columns on the board." << endl;
			cin >> colStart;
		}
		
		//Dynamically allocates memory for a 2D array
		char ** board;
		board = new char*[rows];
		for (int i = 0; i < rows; i++)
		{
			board[i] = new char[cols];
		}

		//Creates an ant object using user input
		Ant ant(board, rowStart, colStart, rows, cols);
		
		/*Moves the ant through the simulation the number of
		steps selected by the user and starting at the user
		specified position. */
		ant.makeMove(board, rowStart, colStart, steps);

		//Free dynamically allocated memory
		for (int i = 0; i < rows; i++)
		{
			delete [] board[i];
		}
		delete[] board;
		
		/*Call menu to prompt user to start simulation again
		quit. */
		int choice = menu();

		/*Quits if user choice was 2, otherwise the simulation 
		starts again. */
		if (choice == 2)
		{
			return 0;
		}
	}
	
	//Quits the program if user's initial choice was to quit
	if (choice == 2)
	{
		cout << "Faretheewell." << endl;
		return 0;
	}

	return 0;
}
