#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// A boolean function that returns true if the region entered by the robot 
// is either a Goal or an Empty unobstacled region

// The function receives the 2D vector string maze (passed by reference) and
// the current position of the robot in the maze

bool path(vector<vector<char>> &maze, int x, int y){

	// If the current position is greater than the maximum size of the maze or 
	// if the current position is a negative number then return false

	if (x> maze.size() - 1 || y>maze.size() - 1 || x<0 || y<0)
	{
		return false;
	}

	// If the position of the robot is the goal then return true
	if (maze[x][y] == 'G')
	{
		maze[x][y] = 'G';
		return true;                           // If exit is reached
	}

	// If the position of the robot is an obstacle or has already been crossed
	// then return false
	if (maze[x][y] == '#' || maze[x][y] == '+')
	{
		return false;
	}

	// As long as the position of the robot is not the Goal or the Starting point or an obstacle, replace 
	// the element with a '+' sign, thereby tracing the path
	if (maze[x][y] != 'G' || maze[x][y] != 'S' || maze[x][y] != '#')
	{
		maze[x][y] = '+';
	}


	// If calling the recursive function on the previous row and same column is true and the
	// element wasn't a Goal or the starting point then replace with a plus sign to trace path of the robot
	// and return true
	if (path(maze, x - 1, y) == true)
	{
		if (maze[x - 1][y] != 'G' || maze[x - 1][y] != 'S')
		{
			maze[x - 1][y] == '+';
		}
		return true;
	}

	// If calling the recursive function on the same row and next column is true and the
	// element wasn't a Goal or the starting point then replace with a plus sign to trace path of the robot
	// and return true
	if (path(maze, x, y + 1) == true)
	{
		if (maze[x][y + 1] != 'G' || maze[x][y + 1] != 'S')
		{
			maze[x][y + 1] == '+';
		}
		return true;
	}

	// If calling the recursive function on the next row and same column is true and the
	// element wasn't a Goal or the starting point then replace with a plus sign to trace path of the robot
	// and return true
	if (path(maze, x + 1, y) == true)
	{
		if (maze[x + 1][y] != 'G' || maze[x + 1][y] != 'S')
		{
			maze[x + 1][y] == '+';
		}
		return true;
	}

	// If calling the recursive function on the same row and previous column is true and the
	// element wasn't a Goal or the starting point then replace with a plus sign to trace path of the robot
	// and return true
	if (path(maze, x, y - 1) == true)
	{
		if (maze[x][y - 1] != 'G' || maze[x][y - 1] != 'S')
		{
			maze[x][y - 1] == '+';
		}
		return true;
	}

	// Replacing the position of the robot with a '.' in case it gets stuck and has to backtrack 
	maze[x][y] = '.';
	return false;
}

int main(){

	// Initializing the position of the robot as the origin - top left corner of the 2D vector
	int startX = 0;
	int startY = 0;

	// Initializing the maze vector where
	// S is the starting position
	// '#' is an obstacle
	// G is the goal
	// '.' constitutes a position open for the robot
	vector<vector<char> > maze = { { 'S', '#', '#', '#', '#', '#' },
	{ '.', '.', '.', '.', '#', '#' },
	{ '#', '.', '#', '#', '#', '#' },
	{ '#', '.', '#', '#', '#', '#' },
	{ '.', '.', '.', '#', 'G', '#' },
	{ '#', '#', '.', '.', '.', '#' } };

	// Space
	cout << endl;
	cout << endl;

	// Displaying the unsolved maze 
	cout << "This is the unsolved maze: " << endl;
	cout << endl;

	for (int i = 0; i < maze.size(); i++)
	{
		for (int j = 0; j < maze[i].size(); j++)
		{
			cout << maze[i][j] << " ";
		}
		cout << endl;
	}

	// Space
	cout << endl;
	cout << endl;

	cout << "This is the solved maze: " << endl;
	cout << endl;

	// If the recursive function returns true, display the solved maze
	if (path(maze, startX, startY) == true)
	{
		cout << endl;
		cout << endl;
		for (int i = 0; i < maze.size(); i++)
		{
			for (int j = 0; j < maze[i].size(); j++)
			{
				maze[0][0] = 'S';
				cout << maze[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	cout << endl;
	cout << endl;
	system("pause");
	return(0);
}
