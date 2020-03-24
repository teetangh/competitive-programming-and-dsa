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
