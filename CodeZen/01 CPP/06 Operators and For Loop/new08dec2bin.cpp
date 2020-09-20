#include <iostream>
using namespace std;

int main()
{
    // Write your code here
    long num;
    cin >> num;

    long rem = 0;
    long revbin = 0;

    while (num != 0)
    {
        rem = num % 2;
        revbin = (revbin * 10) + rem;
        num = num / 2;
    }

    // long rev=0 ;
    // long last=0;
    // while(revbin != 0 )
    // {
    //     last = revbin % 10 ;
    //     rev = ( rev * 10 ) + last;
    //     revbin /= 10;
    // }

    cout << revbin;
}
// Sample Input 1 :
// 12
// Sample Output 1 :
// 1100
// Sample Input 2 :
// 7
// Sample Output 2 :
// 111