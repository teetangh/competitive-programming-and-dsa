#include <iostream>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;

int locate_point_value(pair<int,int> my_pair)
{
	int a = my_pair.first;
	int b = my_pair.second;

	if ((b - a) != 0 && (b - a )!= -2 )
	{
		// cout << "Debug 1"<<endl;
		return -1;
	
	}

	else if (( b - a)  == 0 || (b-a)== -2)
	{
		if (b % 2 == 0)
			return (a + b);
		else
			return (a + b -1);
	}

}



int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("xinput.txt" , "r" , stdin);
	freopen("xoutput.txt" , "w"  , stdout);
#endif
	int test_cases;
	cin >> test_cases;
	int test_cases2 = test_cases;

	std::queue<pair<int,int>> my_queue;

	int a , b;
	while(test_cases--)
	{
		cin >> a >> b;
		my_queue.push(std::make_pair(a,b));
	}
	
	while(test_cases2--)
	{
		int temp_answer =  locate_point_value(my_queue.front());
		my_queue.pop();
		if (temp_answer == -1)
		{
			cout << "No Number"<<endl;
			continue;
		}
		cout << temp_answer << endl;
	}

	return 0;
}