#include <iostream>
#include <bits/stdc++.h>
#include "..\include\CNBinaryTree.hpp"
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;

    Node(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};
Node<int> *constructBST(BinaryTreeNode<int> *root)
{
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
}