#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
    ~Node() {}
};

int main(int argc, char const *argv[])
{
    Node root(1);
    Node n2(2);
    Node n3(3);
    Node n4(4);

    root.left = &n2;
    root.right = &n3;

    n3.left = &n4;

    return 0;
}
