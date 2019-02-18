/**********************************************************************
** Author:          Chelsea Hicks
** Date:            1/17/19
** Description:     The source code file for the menu function, which
**                  prompts the user to either start the simulation
**                  or quit the program. If the user selects start,
**                  the menu seeks user input for the size of the
**                  board, steps in the simulation, and starting
**                  position of the ant.
***********************************************************************/

#include <iostream>
#include <iomanip>
#include "menu.hpp"

using std::cout;
using std::cin;
using std::endl;

int menu()
{
	//Variable to hold the choice the user selects from the menu
	int choice;

	cout << "Welcome to the Langston's Ant Simulation." << endl;
	cout << "Want to see something cool? " << endl;
	cout << "1. Start Langston's Ant Simulation" << endl;
	cout << "2. Quit" << endl;
	cout << "Please enter 1 or 2 to make your selection." << endl;
	cin >> std::setw(1) >> choice;

	/*Checks that user makes a valid selection from the menu options
	* and prompts them to input a valid selection of 1 or 2 until they
	* do. This while loop will check for char values, integers greater
	* than 2 or less than 1. The setw(1) will ensure only the first
	* piece of user input is set to choice. */
	while (!cin.good() || cin.get() != '\n' || choice > 2 || choice < 1)
	{
		cin.clear();
		cin.ignore(256, '\n');
		cout << "ERROR! Please enter a valid selection." << endl;
		cout << "1. Start Langston's Ant Simulation" << endl;
		cout << "2. Quit" << endl;
		cout << "Enter 1 or 2:" << endl;
		cin >> choice;
	}

	//While loop to check and return the choice of the user
	while (choice == 1)
	{
		return 1;
	}

	while (choice == 2)
	{
		return 2;
	}

	return 0;
}

