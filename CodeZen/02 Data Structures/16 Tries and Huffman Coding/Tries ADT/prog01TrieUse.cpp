#include "../include/FINALTrie.hpp"
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    Trie t;
    t.insertWord("and");
    t.insertWord("are");
    t.insertWord("dot");

    cout << t.search("and") << endl;
    t.removeWord("and");
    cout << t.search("and") << endl;

    return 0;
}
