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
        int bucketIndex = getBucketIndex(string key);
        MapNode<V> *head = buckets[bucketIndex];

        while (head != NULL)
        {
            // In case Found
            if (head->key == key)
                return head->value;
            // Iterate the Chain
            head = head->next;
        }

        // In case INVALID key return 0
        return 0;
    }

private:
    int getBucketIndex(string key)
    {
        // Hash Function = Hash Code + Compression Function
        // Will Use Base p hash Code(weighted Polynomial where p is prime)
        int hashCode = 0;

        int currentCoeff = 1;
        for (int i = key.length() - 1; i >= 0; i--)
        {
            hashCode += key[i] * currentCoeff;
            hashCode = hashCode % numBuckets; //To prevent hashCode from exploding

            currentCoeff *= 37;                       // p = 37 is a prime(Trying best to avoid similar hashCode)
            currentCoeff = currentCoeff % numBuckets; //To prevent currentCoeff from exploding
        }

        return hashCode % numBuckets; //To prevent hashCode from exploding
    }

public:
    void insert(string key, V value)
    {
        int bucketIndex = getBucketIndex(string key);
        MapNode<V> *head = buckets[bucketIndex];

        while (head != NULL)
        {
            if (head->key == key)
            {
                head->value = value;
                return;
            }
            head = head->next;
        }
        head = buckets[bucketIndex];
        MapNode<V> *node = new MapNode<V>(key, value);
        node->next = head;
        buckets[bucketIndex] = node;
        count++; // NOT in case of updation ONLY in case of insertion
    }

    V remove(string key)
    {
        int bucketIndex = getBucketIndex(string key);
        MapNode<V> *head = buckets[bucketIndex];
        MapNode<V> *prev = NULL;
        while (head != NULL)
        {
            if (head->key == key)
            {
                // If the node to be deleted is the first node
                if (prev == NULL)
                    buckets[bucketIndex] = head->next;
                // If the node to be deleted is intermediate node
                else
                    prev->next = head->next;

                // Preseving the deleted value
                V value = head->value;

                // if we don't make head's next NULL the entire chain (after head)in Separate Chaining gets deleted
                // Also because the destructor is Recursive in Nature
                head->next = NULL;

                delete head;
                count--;
                return value;
            }
            // Iterating the chain by moving prev and head
            prev = head;
            head = head->next;
        }
        // In case INVALID key return 0
        return 0;
    }
};
