#include <string>
using namespace std;

template <typename V>
class MapNode
{
public:
    string key;
    V value;
    MapNode *next;

    MapNode(string key, V value)
    {
        this->key = key;
        this->value = value;
        next = NULL;
    }

    ~MapNode()
    {
        delete next;
    }
};
template <typename V>
class ourmap
{
private:
    MapNode<V> **buckets;
    int count;
    int numBuckets;

public:
    ourmap()
    {
        count = 0;
        numBuckets = 5;
        buckets = new MapNode<V> *[numBuckets];
        for (int i = 0; i < numBuckets; i++)
            buckets[i] = NULL;
    }
    ~ourmap()
    {
        for (int i = 0; i < numBuckets; i++)
            delete buckets[i];
        delete[] buckets;
    }

    int size()
    {
        return count;
    }

    V getValue(string key)
    {
    }

private:
    int getBucketIndex(string key)
    {
        // Hash Function = Hash Code + Compression Function
        // Will Use Base p hash Code
        int hashCode = 0;

        int currentCoeff = 1;
        for (int i = key.length() - 1; i >= 0; i--)
        {
            hashCode += key[i] * currentCoeff;
            currentCoeff *= 37;
        }

        return hashCode % numBuckets;
    }

public:
    void insert(string key, V value)
    {
        int bucketIndex = getBucketIndex(string key);
    }

    V remove(string key)
    {
    }
};
