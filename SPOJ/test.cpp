/////////////////////////////
/* MY DEFINES*/
// data types
// #define long long ll
// functions
// #define FOR(0,count) for (int i = 0; i < count; ++i)

/////////////////////////////


#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input1.txt" , "r", stdin);
	// for writing output to output.txt
	freopen("output1.txt", "w" , stdout);
#endif
	int i, a, b, c, n = 0, ratio = 1, diff = 0;
	int array[10000][3];

	for (i = 0; i < 100; i++) {
		cin >> array[i][0] >> array[i][1] >> array[i][2];

		if (array[i][0] == 0 && array[i][1] == 0 && array[i][2] == 0 )
			break;

		n++;
	}

	for (i = 0; i < n; i++) {
		a = array[i][0];
		b = array[i][1];
		c = array[i][2];
		if (a > -10000 && b > -10000 && c > -10000 && a < 10000 && b < 10000 && c < 10000) {
			if (c - b == b - a) {
				diff = c - b;
				if (diff != 0)
					cout << "AP " << c + diff << endl;
			}

			else if (c / b == b / a) {
				ratio = c / b;
				if (ratio != 0)
					cout << "GP " << c*ratio << endl;
			}
			else break;
		}
	}

	return 0;

}