#include <iostream>
#include <queue>

using namespace std;

bool isPrime(int number)
{
    if (number < 2)
        return false;

    for (int i = 2; i * i <= number; i++)
        if (number % i == 0)
            return false;
    return true;
}

int main()
{
    int test_cases;
    cin >> test_cases;
    int counter = test_cases;

    queue<pair<int, int>> my_queue;

    while (test_cases--)
    {
        int temp_lower, temp_upper;
        cin >> temp_lower >> temp_upper;

        my_queue.push(std::make_pair(temp_lower, temp_upper));
    }

    while (counter--)
    {
        pair<int, int> temp2 = my_queue.front();
        my_queue.pop();
        for (auto it = temp2.first; it <= temp2.second; it++)
        {
            if (isPrime(it))
                cout << it << endl;
            else
                continue;
        }

        cout << endl;
    }
}