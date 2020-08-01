#include <iostream>
#include <queue>
using namespace std;

int main(int argc, char const *argv[])
{
    queue<int> my_queue;
    int n;
    cin >> n;
    while (n != 42)
    {
        my_queue.push(n);
        cin >> n;
    }

    while (!my_queue.empty())
    {
        int temp = my_queue.front();
        my_queue.pop();
        cout << temp << endl;
    }

    return 0;
}
