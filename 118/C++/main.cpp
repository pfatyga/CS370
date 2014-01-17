/**
 *	Solution to problem 118 - Mutant Flatworld Explorers.
 *	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=3&page=show_problem&problem=54
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Defs
#ifndef NULL
#define NULL 0
#endif

typedef unsigned int uint;

// Constants
const int MAX_COORDINATE = 50;
const int MAX_INSTRUCTION_LENGTH = 100;

const int DIRECTION_NORTH = 0;
const int DIRECTION_EAST = 1;
const int DIRECTION_SOUTH = 2;
const int DIRECTION_WEST = 3;
const int NUM_DIRECTIONS = 4;

/**
*	2D grid. Stores "scents" left by robots;
*/
class World
{
public:
	World( int width, int height )
		: width( width )
		, height( height )
	{
		scentGrid = new bool*[width];
		for ( int i = 0; i < width; i++ )
		{
			scentGrid[i] = new bool[height];

			for ( int j = 0; j < height; j++ )
			{
				scentGrid[i][j] = false;
			}
		}
	}

	~World( )
	{
		if ( scentGrid == NULL )
		{
			return;
		}

		for ( int i = 0; i < width; i++ )
		{
			delete[] scentGrid[i];
		}

		delete[] scentGrid;

		scentGrid = NULL;
	}

	int width;
	int height;
	bool** scentGrid;
};

/**
 *	Moves and turns.
 */
class Robot
{
public:
	Robot( World& world)
		: world( world )
		, x( 0 )
		, y( 0 )
		, direction( DIRECTION_NORTH )
		, isOffWorld( false )
		, instructions( "" )
	{}

	Robot( World& world, int x, int y, int direction, string instructions )
		: world( world )
		, x( x )
		, y( y )
		, direction( direction )
		, instructions( instructions )
	{}

	void moveForward()
	{
		int tempX = x;
		int tempY = y;

		switch ( direction )
		{
		case DIRECTION_NORTH:	tempY++; break;
		case DIRECTION_EAST:	tempX++; break;
		case DIRECTION_SOUTH:	tempY--; break;
		case DIRECTION_WEST:	tempX--; break;
		};

		// If robot will move off of world
		if ( tempX < 0 || tempX >= world.width || tempY < 0 || tempY >= world.height )
		{
			// If there is a scent at current position, do nothing
			if ( world.scentGrid[x][y] == true )
			{
				return;
			}
			// Otherwise, leave scent then move off world
			else
			{
				world.scentGrid[x][y] = true;
				isOffWorld = true;
			}			
		}
		else
		{
			x = tempX;
			y = tempY;
		}
	}

	void turnLeft()
	{
		direction == 0 ? direction = NUM_DIRECTIONS - 1 : direction--;
	}

	void turnRight()
	{
		direction = ( direction + 1 ) % NUM_DIRECTIONS;
	}

	void runInstructions()
	{
		uint index = 0;
		char c;
		while ( index < instructions.length() && !isOffWorld)
		{
			c = instructions.at( index );
			switch ( c )
			{
			case 'F': moveForward();	break;
			case 'L': turnLeft();		break;
			case 'R': turnRight();		break;
			}

			index++;
		}

		char directionAsChar;
		switch ( direction )
		{
		case DIRECTION_NORTH:	directionAsChar = 'N'; break;
		case DIRECTION_EAST:	directionAsChar = 'E'; break;
		case DIRECTION_SOUTH:	directionAsChar = 'S'; break;
		case DIRECTION_WEST:	directionAsChar = 'W'; break;
		}

		cout << x << " " << y << " " << directionAsChar;

		if ( isOffWorld )
		{
			cout << " " << "LOST";
		}

		cout << "\n";
	}

	World& world;
	int x;
	int y;
	int direction;
	bool isOffWorld;
	string instructions;
};

void testFromFile()
{
	ifstream testFile;
	testFile.open( "test.txt" );

	int topRightX, topRightY;
	testFile >> topRightX;
	testFile >> topRightY;

	World world( topRightX + 1, topRightY + 1 );

	while ( !testFile.eof( ) )
	{
		Robot robot( world );

		// Get robot's position, direction, and instructions
		testFile >> robot.x;
		testFile >> robot.y;

		char directionAsChar;
		testFile >> directionAsChar;
		switch ( directionAsChar )
		{
		case 'N': robot.direction = DIRECTION_NORTH;	break;
		case 'E': robot.direction = DIRECTION_EAST;		break;
		case 'S': robot.direction = DIRECTION_SOUTH;	break;
		case 'W': robot.direction = DIRECTION_WEST;		break;
		};

		testFile >> robot.instructions;

		robot.runInstructions( );
	}

	testFile.close( );
}

int main()
{
	//testFromFile();

	int topRightX, topRightY;
	cin >> topRightX;
	cin >> topRightY;

	World world( topRightX + 1, topRightY + 1 );

	while ( !cin.eof( ) )
	{
		Robot robot( world );

		// Get robot's position, direction, and instructions
		cin >> robot.x;
		cin >> robot.y;

		char directionAsChar;
		cin >> directionAsChar;
		switch ( directionAsChar )
		{
		case 'N': robot.direction = DIRECTION_NORTH;	break;
		case 'E': robot.direction = DIRECTION_EAST;		break;
		case 'S': robot.direction = DIRECTION_SOUTH;	break;
		case 'W': robot.direction = DIRECTION_WEST;		break;
		};

		cin >> robot.instructions;

		robot.runInstructions();
	}

	return 0;
}