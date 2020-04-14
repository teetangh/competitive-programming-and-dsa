#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    unordered_map<string, int> ourmap;
    ourmap["abc"] = 1;
    ourmap["abc2"] = 2;
    ourmap["abc3"] = 3;
    ourmap["abc4"] = 4;
    ourmap["abc5"] = 5;
    ourmap["abc6"] = 6;

    unordered_map<string, int>::iterator it = ourmap.begin();
    while (it != ourmap.end())
    {
        cout << "Key : " << it->first << " Value : " << it->second << endl;
        it++;
    }

    // Find
    unordered_map<string, int>::iterator it2 = ourmap.find("abc");
    cout << "Key : " << it2->first << " Value : " << it2->second << endl;
    // ourmap.erase(it2, it2 + 4); // from it2 to (it2 + 3)  //NOT Working though

    cout << endl;
    // erase examples:
    ourmap.erase(ourmap.begin()); // erasing by iterator
    for (auto &x : ourmap)
        std::cout << x.first << ": " << x.second << std::endl;
    cout << endl;

    ourmap.erase("abc5"); // erasing by key
    for (auto &x : ourmap)
        std::cout << x.first << ": " << x.second << std::endl;

    cout << endl;
    ourmap.erase(ourmap.find("abc3"), ourmap.end()); // erasing by range

    for (auto &x : ourmap)
        std::cout << x.first << ": " << x.second << std::endl;

    cout << endl;

    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    vector<int>::iterator it1 = v.begin();
    while (it1 != v.end())
    {
        cout << *it1 << " ";
        it1++;
    }

    return 0;
}

// // Output
// Key : abc6 Value : 6
// Key : abc5 Value : 5
// Key : abc4 Value : 4
// Key : abc3 Value : 3
// Key : abc Value : 1
// Key : abc2 Value : 2
// Key : abc Value : 1

// abc5: 5
// abc4: 4
// abc3: 3
// abc: 1
// abc2: 2

// abc4: 4
// abc3: 3
// abc: 1
// abc2: 2

// abc4: 4

// 1 2 3 4 5