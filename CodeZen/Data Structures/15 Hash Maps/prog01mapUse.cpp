// Map -> BST -> log(n)
// Unordered_map -> Hashtable -> O(1)
// Set -> BST -> log(n)
// Unordered_set -> Hashtable -> O(1)
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    unordered_map<string, int> ourMap;

    // insert
    pair<string, int> p("abc", 1);
    ourMap.insert(p);
    ourMap["def"] = 1; //for updating keys

    // Find or Access elements
    cout << ourMap["abc"] << endl;
    cout << ourMap.at("abc") << endl;

    // cout << ourMap.at("ghi") << endl; //Throws exception when key missing
    cout << "Size :" << ourMap.size() << endl;
    cout << ourMap["ghi"] << endl; // Default value = 0 for non-existent items
    cout << "Size :" << ourMap.size() << endl;

    // Check Frequency
    if (ourMap.count("ghi") > 0)
        cout << "ghi is present" << endl;

    // Erase an element
    ourMap.erase("ghi");
    if (ourMap.count("ghi") > 0)
        cout << "ghi is present" << endl;
    else
        cout << "ghi is NOT present" << endl;

    cout << "Size :" << ourMap.size() << endl;
    return 0;
}
