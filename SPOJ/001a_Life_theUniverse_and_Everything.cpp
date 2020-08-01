#include <iostream>
#include <queue>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    queue<int> mq;

    cin >> n;

    while (n != 42)
    {
        mq.push(n);
        cin >> n;
    }

    while (!(mq.empty()))
    {
        int temp = mq.front();
        mq.pop();
        cout << temp << endl;
    }

    return 0;
}
