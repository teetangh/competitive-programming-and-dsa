#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;

int f(int A, int B, int C)
{
    priority_queue<int> gquiz;
    gquiz.push(A);
    gquiz.push(B);
    gquiz.push(C);
    gquiz.pop();
    return gquiz.top();
}
int main()
{
    // your code goes here
    ll t;
    cin >> t;
    while (t--)
    {
        int A, B, C;
        cin >> A >> B >> C;
        cout << f(A, B, C) << endl;
    }
    return 0;
}