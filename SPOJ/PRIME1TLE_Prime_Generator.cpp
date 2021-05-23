#include <iostream>
#include <queue>
using namespace std;

bool isPrime(int num)
{
    if (num < 2)
        return false;
    
    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

void primeGenerator(pair<int, int> my_pair)
{
    for (auto it = my_pair.first; it <= my_pair.second; it++)
    {
        if (isPrime(it))
        {
            cout << it << endl;
        }
    }
}

int main(int argc, char const *argv[])
{
    int test_cases;
    cin >> test_cases;

    int temp = test_cases;
    queue<pair<int, int>> my_queue;
    while (test_cases--)
    {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        pair<int, int> my_pair = std::make_pair(temp1, temp2);
        my_queue.push(my_pair);
    }

    while (!my_queue.empty())
    {
        pair<int, int> my_pair2 = my_queue.front();
        primeGenerator(my_pair2);
        cout << endl;
        my_queue.pop();
    }

    return 0;
}
