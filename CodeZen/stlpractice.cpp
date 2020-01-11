#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";

    vector<int>::iterator it = v.begin();

    cout << v.size() << endl;
    // vector<int> v ::iterator it;
    // iterator it = v.begin();
}