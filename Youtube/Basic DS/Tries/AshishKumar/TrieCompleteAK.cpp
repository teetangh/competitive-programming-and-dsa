#include <iostream>
#include <string>
#include <bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

struct Trie
{
    struct Trie *children[26];
    bool endOfWord;
};

struct Trie *getNode(void)
{
    struct Trie *pnode = new Trie;
    pnode->endOfWord = false;
    for (int i = 0; i < 26; i++)
        pnode->children[i] = NULL;

    return pnode;
};

void insert(struct Trie *root, string s)
{
    struct Trie *p = root;
    int n = s.length();

    for (int i = 0; i < n; i++)
    {
        int k = s[i] - 'a';
        if (!p->children[k])
            p->children[k] = getNode();

        p = p->children[k];
    }

    p->endOfWord = true;
}

bool search(struct Trie *root, string s)
{
    struct Trie *p = root;
    int n = s.length();

    for (int i = 0; i < n; i++)
    {
        int k = s[i] - 'a';
        if (p->children[k] == NULL)
            return false;

        p = p->children[k];
    }

    return (p != NULL && p->endOfWord);
}

int main(int argc, char const *argv[])
{
    struct Trie *root = getNode();

    insert(root, "ab");
    insert(root, "abcde");
    insert(root, "abcdep");

    cout << " searching abc " << search(root, "abc") << endl;
    cout << " searching abcd " << search(root, "abcd") << endl;
    cout << " searching abcde " << search(root, "abcde") << endl;
    cout << " searching abcdef " << search(root, "abcdef") << endl;
    return 0;
}
