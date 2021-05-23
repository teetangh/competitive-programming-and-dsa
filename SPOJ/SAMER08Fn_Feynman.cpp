#include <iostream>
#include <queue>
using namespace std;

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDDGE
	freopen("xinput.txt" , "r" , stdin);
	freopen("xoutput.txt" , "w" , stdout);
#endif

	queue<int> mq;

	int n;

	cin >> n;
	mq.push(n);	

	while ( n != 0 )
	{
		cin >> n;
		mq.push(n);
	}

	while (!mq.empty())
	{
		if (mq.front() == 0)
			break;

		int side = (mq.front());
		mq.pop();	
		cout << (side * (side + 1) * (2 * side + 1)) / 6 << endl;
	}

	return 0;
}