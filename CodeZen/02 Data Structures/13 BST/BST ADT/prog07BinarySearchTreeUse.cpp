#include <iostream>
// #include <bits/stdc++.h>
#include <vector>
#include "..\include\BinarySearchTree.hpp"
using namespace std;

int main(int argc, char const *argv[])
{
    BST b;
    b.insertData(10);
    b.insertData(5);
    b.insertData(20);
    b.insertData(7);
    b.insertData(3);
    b.insertData(15);

    cout << "\nAFTER INSERTION\n";
    b.printTree();

    b.deleteData(10);
    b.deleteData(100);
    cout << "\nAFTER DELETION\n";
    b.printTree();

    return 0;
}
