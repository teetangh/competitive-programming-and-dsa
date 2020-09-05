// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Defines
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

// typedefs
typedef long long ll;
typedef long long int lli;

#include <bits/stdc++.h>

void printSolution(vector<vector<int>> vec)
{
    for(int i = 0 ; i < vec.size() ; i++)
	{
        for(int j = 0 ; j < vec[0].size() ; j++)
        {
            cout << vec[i][j] << " ";
        }
    }
    cout << endl;
} 

bool canPlaceQueen(vector<vector<int>> , int i , int j)
{
    for(int i2 = 0 ; i2 < vec.size() ; i2++)
        if(vec[i2][j] == 1)return false;
    
    for(int j2 = 0 ; j2 < vec[0].size() ; j2++)
        if(vec[i][j2] == 1)return false;
    
    int i2 = 0;
    int j2 = 0;
    for( ;i2<vec.size();i2++)
    {
        for(; j2<vec[0].size() ; j2++)
        {
            if((i2 - i  == j2 - j) && (arr[i2][j2] == arr[i][j]))
                return false;    
        	if((i - i2  == j2 - j) && (arr[i2][j2] == arr[i][j]))
                return false;
        }
    }
    
    return true;
}

bool placeNQueensHelper(vector<vector<int>> vec,int n , int row ,int col)
{
    if(row >= vec.size()-1 && col == vec[0].size())
        return true;
    
    if(col >= vec[0].size())
    	return false;
    
    if(row>=vec.size())
    {
        printSolution(vec);
        return true;
    }
    
    vec[row][col] = 1;
    bool flagRowPlaced = false;
    for(int j = 0 ; j < vec[0].size() ; j++)
    {
        if(canPlaceQueen(vec,i,j))
        {
            vec[row + 1][j] = 1;
			flagRowPlaced = true;
        }
    }
    
    if(flagRowPlaced == false)
        return false;
    
    bool placeNextRow = placeNQueensHelper(vec,n,row + 1,0);
    
    if(row < vec.size() - 1 )
    {
		if(placeNextRow)
    		return placeNQueensHelper(vec,n,row,)
    }
    else
    {
        vec[row][col] = 0;
        return placeNQueensHelper(vec,n,row,col+1);     
	}
        
	// if(row == vec.size() - 1 && placeNextRow)
	// {
	// vec[row][col] = 0;
	// 	return placeNQueensHelper(vec,n,row,col + 1);
	// }
	// else if()
	// return placeNQueensHelper(vec,n,row,col + 1);

}
void placeNQueens(int n){

	if (n == 1)
    {   
        cout << "1" <<endl;
        return;
    }
    else if (n == 2 || n == 3)
        return;
    
    //2d vector of n*n initialised with 0     
    int default_value = 0;
    vector<vector<int>> vec;
    vec.resize(n,vector<int>(n,default_value));
    
    // vec[0][0] = 1;
    for(int i = 1  ; i < vec.size() ; i++)
    {
        if(placeNQueenHelper(vec,n,i))
			continue;
        else
            
    }

}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    placeNQueens(n);
}
