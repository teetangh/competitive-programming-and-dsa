#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>

using namespace std;

void printSolution(vector<vector<int>> output_matrix)
{
    for (int i = 0; i < output_matrix.size(); i++)
    {
        for (int j = 0; j < output_matrix[i].size(); j++)
        {
            cout << output_matrix[i][j] << " ";
        }
    }
    cout << endl;
}
void ratInAMazeHelper(vector<vector<int>> input_matrix, vector<vector<int>> output_matrix, int x, int y)
{
    if (x == (output_matrix.size() - 1) && y == (output_matrix.size() - 1))
    {
        printSolution(output_matrix);
        // output_matrix[x][y] = 0;
        return;
    }

    if (x <= -1 || x >= output_matrix.size())
        return;
    if (y <= -1 || y >= output_matrix.size())
        return;

    if (input_matrix[x][y] == 0)
        return;

    output_matrix[x][y] = 1;
    ratInAMazeHelper(input_matrix, output_matrix, x - 1, y);
    ratInAMazeHelper(input_matrix, output_matrix, x + 1, y);
    ratInAMazeHelper(input_matrix, output_matrix, x, y - 1);
    ratInAMazeHelper(input_matrix, output_matrix, x, y + 1);
    output_matrix[x][y] = 0;


    return;
}
void ratInAMaze(vector<vector<int>> input_matrix, vector<vector<int>> output_matrix)
{
    int x, y;
    x = y = 0;
    ratInAMazeHelper(input_matrix, output_matrix, x, y);
}

int main()
{
    int maze_size;
    cin >> maze_size;

    int default_value = 0;
    vector<vector<int>> input_matrix;
    input_matrix.resize(maze_size, vector<int>(maze_size, default_value));
    vector<vector<int>> output_matrix;

    for (int i = 0; i < maze_size; i++)
    {
        for (int j = 0; j < maze_size; j++)
        {
            cin >> input_matrix[i][j];
        }
    }

    ratInAMaze(input_matrix, output_matrix);

    return 0;
}
