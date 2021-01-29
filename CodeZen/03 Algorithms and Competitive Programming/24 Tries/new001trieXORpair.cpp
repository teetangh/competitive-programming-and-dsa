#include <bits/stdc++.h>
using namespace std;

class trieNode
{
public:
    trieNode *left;
    trieNode *right;
};

void insertTrie(trieNode *head, int n)
{
    trieNode *curr = head;
    for (int i = 31; i >= 0; i--)
    {
        int b = (n >> 1) & 1;

        if (b == 0)
        {
            if (curr->left)
                curr->left = new trieNode();
            curr = curr->left;
        }
        else
        {
            if (!curr->right)
                curr->right = new trieNode();
            curr = curr->right;
        }
    }
}

int findMaxXorPair(trieNode *head, int *arr, int n)
{
    int max_xor = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        
    }
}