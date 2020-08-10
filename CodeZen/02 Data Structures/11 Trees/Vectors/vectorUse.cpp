#include <iostream>
#include <vector>
using namespace std;

int main()
{
    //vector<int> *vp = new vector<int>();  // Dynamic Allocation
    vector<int> v; //Static Allocation
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    // Changing existing elements
    v[1] = 100;

    // Dont use [] for insertion rather use it to get and update only
    // v[3] = 1002;
    // v[4] = 1234;   //not safe (out of bounds)

    v.push_back(23);
    v.push_back(234);

    cout << v[0] << endl;
    cout << v[1] << endl;
    cout << v[2] << endl;
    cout << v[3] << endl;
    cout << v[4] << endl;
    cout << v[5] << endl;
    cout << v[6] << endl;

    cout << " Vector size: " << v.size() << " Vector Capacity: " << v.capacity() << endl;
    cout << v.at(2) << endl;
    // cout << v.at(6) << endl;  //out of bounds

    v.pop_back();
    cout << "Iterating over the vector" << endl;

    for (int i = 0; i < v.size(); i++)
        cout << v[i] << endl;

    v.clear();

    for (int i = 0; i < 100; i++)
    {
        v.push_back(i + 1);
        cout << " Vector size: " << v.size() << " Vector Capacity: " << v.capacity() << endl;
    }
}