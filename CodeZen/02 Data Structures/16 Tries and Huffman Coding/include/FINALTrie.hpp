#include "TrieNode.hpp"
#include <string>
class Trie
{
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode('\0');
    }

    // INSERT WORD
private: //Helper Function
    void insertWord(TrieNode *root, string word)
    {
        // Base Case
        if (word.size() == 0)
        {
            root->isTerminal = true;
            return;
        }
        // Small Calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
            child = root->children[index];
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive Call
        insertWord(child, word.substr(1));
    }

public: // For User
    void insertWord(string word)
    {
        insertWord(root, word);
    }

    // REMOVE WORD
private: //Helper Function
    void removeWord(TrieNode *root, string word)
    {
        // Base Case
        if (word.size() == 0)
        {
            root->isTerminal = true;
            return;
        }
        // Small Calculation
        TrieNode *child;
        int index = word[0] - 'a';
        if (root->children[index] != NULL)
            child = root->children[index];
        else
            return;

        removeWord(child, word.substr(1));

        // Remove child Node if it is useless
        if (child->isTerminal == false)
        {
            // Check if it has further no children
            for (int i = 0; i < 26; i++)
            {
                if (child->children[i] != NULL)
                    return;
            }

            delete child;
            root->children[index] = NULL;
        }
    }

public: // For User
    void removeWord(string word)
    {
        removeWord(root, word);
    }
    // SEARCH FUNCTION
private: //Helper Function
    bool search(TrieNode *root, string word)
    {
        if (word.size() == 0)
        {
            return root->isTerminal;
        }

        // Small Calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            return false;
        }

        // Recursive call
        return search(child, word.substr(1));
    }

public: // For User
    bool search(string word)
    {
        return search(root, word);
    }

    // ~Trie();
};
