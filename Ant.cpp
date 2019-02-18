/************************************************************************
** Author:          Chelsea Hicks
** Date:            1/17/19
** Description:     The source code file for the Ant class and functions
**		    to run the simulation of Langston's Ant.
*************************************************************************/

#include <iostream>
#include <iomanip>
#include "Ant.hpp"

using std::cout;
using std::cin;
using std::endl;

/*Constructor takes a pointer to a 2D array of pointers to char
sets the starting position for the ant, and creates the board
from the user input for number of rows and columns. */
Ant::Ant(char ** boardIn, int rowStart, int colStart, int rowsIn, int colsIn)
{
	
	board = boardIn;
	rows = rowsIn;
	cols = colsIn;

	for (int row = 0; row < rows; row++)
	{
		for (int col = 0; col < cols; col++)
		{
			board[row][col] = ' ';
		}
	}
	rowPos = rowStart;
	colPos = colStart;
	
}

//Function returns the row position of the ant
int Ant::getRowPos()
{
	return rowPos;
}

//Function returns the column position of the ant
int Ant::getColPos()
{
	return colPos;
}

//Function returns the number of rows on the board
int Ant::getRows()
{
	return rows;
}

//Function returns the number of columns on the board
int Ant::getCols()
{
	return cols;
}

/*Function uses the getRows() and getCols() functions to
get the number of rows and columns entered by the user
and uses a for loop to print out the contents of the board. */
void Ant::printBoard()
{
	int rows = getRows();
	int cols = getCols();
	
	cout << endl;
	
	for (int row = 0; row < rows; row++)
	{
		for (int col = 0; col < cols; col++)
		{
			cout << board[row][col];
		}
		cout << endl;
	}
		
}

/*Function loops through moving the ant, updating and printing
the board the number of steps the user wants to run the simulation. */
void Ant::makeMove(char ** board, int colPos, int rowPos, int steps)
{
	direction orientation = NORTH;

	rowPos = rowPos - 1;
	colPos = colPos - 1;

	//Changes the ant's starting position to black before moving
	board[rowPos][colPos] = '#';

	/*Loop keeps track of the number of ant moves that occur and runs 
	 until the user declared number of steps is reached. */
	for (int counter = 0; counter < steps; counter++)
	{	
		cout << "Step number: " << counter + 1 << endl;
	
		//Prints only the ant to the board if the board is 1x1
		if (rows == 1 && cols == 1)
		{
			board[rowPos][colPos] = '*';
			printBoard();
			break;
		}

		/*Switch statement takes in the orientation of the ant
		and based on the direction the ant is facing,
		checks if the ant is about to head out of bound and
		if it is, turns the ant the opposite direction. Next,
		it checks if the position the ant is moving to is white 
		or black. From this determination, inside an if statement,
		the rowPos of the ant is updated for its move, the ant is
		moved to that position, the next orientation is determined
		calling the nextDirection member function, the board is printed,
		and the position of the ant is updated with its change to white
		or black for the next printing.*/ 
		
		switch (orientation)
		{
			case NORTH:
			/*Checks if next position of the ant will be out of bounds
			and updates to the opposite direction if it will, subtracts
			from the counter before breaking out of the switch since a
			move doesn't happen here, this only changes the direction. */
			if ((rowPos - 1) < 0)
			{
				orientation = SOUTH;
				counter--;
				break;
			}
			
			//Makes a move based on the position being white
			if (board[rowPos - 1][colPos] == ' ')
			{
				rowPos = rowPos - 1;
				board[rowPos][colPos] = '*';
				orientation = nextDirection(NORTH, ' ');
				printBoard();
				board[rowPos][colPos] = '#';
				break;
			}
			
			//Makes a move based on the position being black
			if (board[rowPos - 1][colPos] == '#')
			{
				rowPos = rowPos - 1;
				board[rowPos][colPos] = '*';
				orientation = nextDirection(NORTH, '#');
				printBoard();
				board[rowPos][colPos] = ' ';
				break;
			}

			case EAST:
			if ((colPos + 1) > (cols - 1))
			{
				orientation = WEST;
				counter--;
				break;
			}

			if (board[rowPos][colPos + 1] == ' ')
			{
				colPos = colPos + 1;
				board[rowPos][colPos] = '*';
				orientation = nextDirection(EAST, ' ');
				printBoard();
				board[rowPos][colPos] = '#';
				break;
			}
			
			if (board[rowPos][colPos + 1] == '#')
			{
				colPos = colPos + 1;
				board[rowPos][colPos] = '*';
				orientation = nextDirection(EAST, '#');
				printBoard();
				board[rowPos][colPos] = ' ';
				break;
			}

			case SOUTH:
			if ((rowPos + 1) > (rows - 1))
			{
				orientation = NORTH;
				counter--;
				break;
			}
			
			if (board[rowPos + 1][colPos] == ' ')
			{
				rowPos = rowPos + 1;
				board[rowPos][colPos] = '*';
				orientation = nextDirection(SOUTH, ' ');
				printBoard();
				board[rowPos][colPos] = '#';
				break;
			}
			
			if (board[rowPos + 1][colPos] == '#')
			{
				rowPos = rowPos + 1;
				board[rowPos][colPos] = '*';
				orientation = nextDirection(SOUTH, '#');
				printBoard();
				board[rowPos][colPos] = ' ';
				break;
			}

			case WEST:
			if ((colPos - 1) < 0)
			{
				orientation = EAST;
				counter--;
				break;
			}

			if (board[rowPos][colPos - 1] == ' ')
			{
				colPos = colPos - 1;
				board[rowPos][colPos] = '*';
				orientation = nextDirection(WEST, ' ');
				printBoard();
				board[rowPos][colPos] = '#';
				break;
			}
			
			if (board[rowPos][colPos - 1] == '#')
			{
				colPos = colPos - 1;
				board[rowPos][colPos] = '*';
				orientation = nextDirection(WEST, '#');
				printBoard();
				board[rowPos][colPos] = ' ';
				break;
			}
		}
	}
}

//Function determines and returns next direction of the ant
direction Ant::nextDirection(direction orientation, char state)
{
	direction nextDirection = NORTH;
	
	/*If the state is black, the direction will shift 90 degrees
	to the left. */
	if (state == '#')
	{
		switch (orientation)
		{
			case NORTH:
			nextDirection = WEST;
			return nextDirection;
			break;

			case EAST:
			nextDirection = NORTH;
			return nextDirection;
			break;

			case SOUTH:
			nextDirection = EAST;
			return nextDirection;
			break;

			case WEST:
			nextDirection = SOUTH;
			return nextDirection;
			break;
		}
	}
	/*If the state if white, the direction turns 90 degrees to the
	right. */
	else if (state == ' ')
	{
		switch (orientation)
		{
			case NORTH:
			nextDirection = EAST;
			return nextDirection;
			break;

			case EAST:
			nextDirection = SOUTH;
			return nextDirection;
			break;

			case SOUTH:
			nextDirection = WEST;
			return nextDirection;
			break;

			case WEST:
			nextDirection = NORTH;
			return nextDirection;
			break;
		}
	}

	return nextDirection;
}


