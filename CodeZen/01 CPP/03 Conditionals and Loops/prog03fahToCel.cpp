#include <iostream>
using namespace std;

int main()
{

    /*  Read input as specified in the question.
	* Print output as specified in the question.
	*/
    int start, stop, step;
    cin >> start;
    cin >> stop;
    cin >> step;
    int c;
    for (int i = start; i <= stop; i = i + step)
    {
        c = ((i - 32) * ((float)5 / 9));
        cout << i << "\t" << c << endl;
    }
}
// Sample Input 1:
// 0 
// 100 
// 20
// Sample Output 1:
// 0   -17
// 20  -6
// 40  4
// 60  15
// 80  26
// 100 37
// Sample Input 2:
// 20
// 119
// 13
// Sample Output 2:
// 20  -6
// 33  0 
// 46  7
// 59  15
// 72  22
// 85  29
// 98  36
// 111 43