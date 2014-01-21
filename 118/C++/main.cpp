/**
 *	Solution to problem 118 - Mutant Flatworld Explorers.
 *	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=3&page=show_problem&problem=54
 */

#include <stdio.h>
#include <iostream>
#include <string>

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

const int TURN_RIGHT[] = { DIRECTION_EAST, DIRECTION_SOUTH, DIRECTION_WEST, DIRECTION_NORTH };
const int TURN_LEFT[] =  { DIRECTION_WEST, DIRECTION_NORTH, DIRECTION_EAST, DIRECTION_SOUTH };
const char DIRECTIONS_AS_CHARS[] = { 'N', 'E', 'S', 'W' };

/**
*	Contains 2D grid. Stores "scents" left by robots;
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
		if ( scentGrid != NULL )
		{
			for ( int i = 0; i < width; i++ )
			{
				if ( scentGrid[i] != NULL )
				{
					delete[] scentGrid[i];
					scentGrid[i] = NULL;
				}
			}

			delete[] scentGrid;

			scentGrid = NULL;
		}
	}

	int width;
	int height;
	bool** scentGrid;
};

class Robot
{
public:
	Robot( World& world )
		: world( world )
		, x( 0 )
		, y( 0 )
		, direction( DIRECTION_NORTH )
		, isOffWorld( false )
		, instructions( "" )
	{}

	void moveForward()
	{
		int nextX = x;
		int nextY = y;

		switch ( direction )
		{
		case DIRECTION_NORTH:	nextY++;	break;
		case DIRECTION_EAST:	nextX++;	break;
		case DIRECTION_SOUTH:	nextY--;	break;
		case DIRECTION_WEST:	nextX--;	break;
		default:				return;		break;
		};

		// If robot will move off of world
		if ( nextX < 0 || nextX >= world.width || nextY < 0 || nextY >= world.height )
		{
			// If there is a scent at current position, do nothing
			if ( world.scentGrid[x][y] == true )
			{
				return;
			}
			// Otherwise, leave scent
			else
			{
				world.scentGrid[x][y] = true;
				isOffWorld = true;
			}			
		}
		else
		{
			x = nextX;
			y = nextY;
		}
	}

	void turnLeft()
	{
		direction = TURN_LEFT[direction];
	}

	void turnRight()
	{
		direction = TURN_RIGHT[direction];
	}

	void runInstructions()
	{
		uint index = 0;
		char c;
		while ( index < instructions.length() && !isOffWorld )
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

		cout << x << " " << y << " " << DIRECTIONS_AS_CHARS[direction];

		if ( isOffWorld )
		{
			cout << " LOST";
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

int main()
{
	int topRightX, topRightY;
	cin >> topRightX;
	cin >> topRightY;

	if ( topRightX > 50 )
	{
		topRightX = 50;
	}

	if ( topRightY > 50 )
	{
		topRightY = 50;
	}

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