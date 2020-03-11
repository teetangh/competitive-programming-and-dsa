#include <iostream>
using namespace std;
int main()
{
    //code
    int t;
    cin >> t;

    int size, positions;
    int myVec[201][201];
    int i, j, k;
    for (i = 0; i < t; i++)
    {
        cin >> size >> positions;
        myVec[i][0] = size;
        for (j = 1; j <= size; j++)
            cin >> myVec[i][j];

        for (j = 0; j < positions; j++)
        {
            int temp = myVec[i][1];
            for (int k = 1; k <= size; k++)
                myVec[i][k] = myVec[i][k + 1];
            myVec[i][k] = temp;
        }
    }

    for (i = 0; i < t; i++)
    {
        for (j = 1; j <= myVec[i][0]; j++)
        {
            cout << myVec[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}