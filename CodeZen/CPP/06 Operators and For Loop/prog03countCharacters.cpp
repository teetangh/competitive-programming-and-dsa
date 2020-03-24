#include <iostream>
using namespace std;

int main()
{

    /* Read input as specified in the question.
	 * Print output as specified in the question.
	 */
    int letterCount = 0;
    int numCount = 0;
    int spaceCount = 0;

    char c = cin.get();
    do
    {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
            letterCount++;
        if ((c >= '0' && c <= '9'))
            numCount++;
        if ((c == ' ' || c == '\t' || c == '\n'))
            spaceCount++;
        c = cin.get();

    } while (c != '$');

    cout << letterCount << " " << numCount << " " << spaceCount;
}
