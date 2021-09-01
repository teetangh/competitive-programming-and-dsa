// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Defines
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

typedef long long ll;

///////////////////////////////////////////////////////////////////

struct trieMemoryEfficient
{
    bool is_end;
    unordered_map<char, trieMemoryEfficient *> mp;

    trieMemoryEfficient()
    {
        is_end = false;
    }
};
struct trieMemoryEfficient *rootMemoryEfficient;

void insertMemoryEfficient(string str)
{
    trieMemoryEfficient *curr = rootMemoryEfficient;
    for (char ch : str)
    {
        if (!curr->mp.count(ch))
            curr->mp[ch] = new trieMemoryEfficient();
        curr = curr->mp[ch];
    }
    curr->is_end = true;
}

bool searchMemoryEfficient(string str)
{
    trieMemoryEfficient *curr = rootMemoryEfficient;
    for (char ch : str)
    {
        if (!curr->mp.count(ch))
            return false;
        curr = curr->mp[ch];
    }
    return curr->is_end;
}

///////////////////////////////////////////////////////////////////
struct trie
{

    struct trie *child[26]; // 0-25 indicates a-z
    bool is_end;            // indicates end of word

    trie()
    {
        memset(child, 0, sizeof(child));
        is_end = false;
    }
};

struct trie *root;

void insert(string str)
{
    trie *curr = root;
    for (char ch : str)
    {
        int idx = ch - 'a';
        if (curr->child[idx] == NULL)
        {
            curr->child[idx] = new trie();
        }
        curr = curr->child[idx];
    }
    curr->is_end = true;
}

bool search(string str)
{
    struct trie *curr = root;
    for (char ch : str)
    {
        int idx = ch - 'a';
        if (curr->child[idx] == NULL)
            return false;
        curr = curr->child[idx];
    }
    return curr->is_end;
}

void remove(string str)
{
    struct trie *curr = root;
    for (char ch : str)
    {
        int idx = ch - 'a';
        if (curr->child[idx] == NULL)
            return;
        curr = curr->child[idx];
    }
    curr->is_end = false;
}
///////////////////////////////////////////////////////////////////

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);   // for getting input from xinput.txt
    freopen("xoutput.txt", "w", stdout); // for writing output to xoutput.txt
#endif

    fastio;

    ll tc;
    cin >> tc;

    // root = new trie();
    rootMemoryEfficient = new trieMemoryEfficient();

    while (tc--)
    {
        string str;
        cin >> str;
        insertMemoryEfficient(str);
    }

    cin >> tc;
    while (tc--)
    {
        string str;
        cin >> str;
        if (searchMemoryEfficient(str))
            cout << str << " is present" << endl;
        else
            cout << str << " is not present" << endl;
    }

    return 0;
}
