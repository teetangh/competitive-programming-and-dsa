#include <iostream>
using namespace std;
// #include "Solution.h"

void printSolution(int maze[][20], int n, int path[][20])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << path[i][j] << " ";
        }
    }
    cout << endl;
}

void ratInAMazeHelper(int maze[][20], int n, int path[][20], int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= n)
        return;

    if (maze[x][y] == 0 || path[x][y] == 1)
        return;

    if (x == n - 1 && y == n - 1)
    {
        path[x][y] = 1;
        printSolution(maze, n, path);
        path[x][y] = 0;
        return;
    }

    path[x][y] = 1;
    ratInAMazeHelper(maze, n, path, x - 1, y);
    ratInAMazeHelper(maze, n, path, x + 1, y);
    ratInAMazeHelper(maze, n, path, x, y - 1);
    ratInAMazeHelper(maze, n, path, x, y + 1);
    path[x][y] = 0;
}

void ratInAMaze(int maze[][20], int n)
{

    int path[20][20] = {0};
    ratInAMazeHelper(maze, n, path, 0, 0);
}
int main()
{

    int n;
    cin >> n;
    int maze[20][20];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> maze[i][j];
        }
    }
    ratInAMaze(maze, n);
}
