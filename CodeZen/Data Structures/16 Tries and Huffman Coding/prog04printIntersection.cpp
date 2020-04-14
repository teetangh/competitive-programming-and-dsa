#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// input1 - first array
// input2 - second array
// size1 - size of first array
// size2 - size of second array

void intersection(int input1[], int input2[], int size1, int size2)
{
    unordered_map<int, int> present1;
    unordered_map<int, int> present2;

    for (int i = 0; i < size1; i++)
        present1[input1[i]]++;
    for (int i = 0; i < size2; i++)
        present2[input2[i]]++;

    for (auto it = present1.begin(); it != present1.end(); it++)
    {
        while (present1[it->first] > 0 && present2[it->first] > 0)
        {
            cout << it->first << endl;
            present1[it->first]--;
            present2[it->first]--;
        }
    }
}
int main()
{

    int size1, size2;

    cin >> size1;
    int *input1 = new int[1 + size1];

    for (int i = 0; i < size1; i++)
        cin >> input1[i];

    cin >> size2;
    int *input2 = new int[1 + size2];

    for (int i = 0; i < size2; i++)
        cin >> input2[i];

    intersection(input1, input2, size1, size2);

    return 0;
}
