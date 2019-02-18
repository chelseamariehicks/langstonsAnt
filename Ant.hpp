/*************************************************************************
** Author:          Chelsea Hicks
** Date:            1/17/19
** Description:     The header file for the Ant class, which declares
**                  all functions and variables pertaining to
**		    the Langston's Ant program, including the 
**		    declaration of an ant object to initialize an
**		    ant, its location, and direction. This header file
**		    also declares a function to be used to print the
**		    board created in antMain.cpp, a function to make
**		    all the moves of the ant, and a function to determine
**		    the next direction of the ant.
*************************************************************************/

#ifndef ANT_HPP
#define ANT_HPP

/*Declaring enum variable before and outside class declaration
that represents the direction the ant is facing. */
enum direction {NORTH, EAST, SOUTH, WEST};

class Ant
{
	/*Declare the data members of the Ant class: a pointer to a pointer
	of chars, an enum variable referring to the direction of the ant,
	int variables for the row and column position of the ant, and 
	int variables for the number of rows and columns on the board. */
	private:
		char ** board;
		direction orientation;
		int rowPos, colPos;
		int rows, cols;
	
	/*Declares a constructor, get methods to return the number of rows
	and columns on the board and the specific row and column position
	of the ant, a method to print the board, and a method to make
	all of the moves of the ant based on user input for where to start
	and how many steps to run in the simulation. */
	public:
		Ant(char **, int, int, int, int); 
		int getRowPos();
		int getColPos();
		int getRows();
		int getCols();
		void printBoard();
		void makeMove(char **, int, int, int);
		direction nextDirection(direction, char);
};

#endif
