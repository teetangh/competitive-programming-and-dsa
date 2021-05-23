#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int calculate_factorial(std::map<int, int> factorial_table , int num )
{
	auto it = factorial_table.find(num);
	if (it != factorial_table.end())
		return it->second;


	int temp_product = 1;

	for (int i = num; i >= 1 ; i--)
	{
		temp_product *= i;
		// cout <<"Debug 1" <<endl;
		auto it = factorial_table.find(i);
		if (it != factorial_table.end())
		{
			cout << " Here ";
			return it->second;
		}
	}
	return temp_product;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("xinput.txt", "r" , stdin);
	freopen("xoutput.txt", "w", stdout);
#endif

	int test_cases;
	cin >> test_cases;
	int test_cases2 = test_cases; 
	// cout << test_cases;

	std::map<int, int> factorial_table;
	queue <int> mq;

	int n;
	while(test_cases--)
	{
		cin >> n;
		mq.push(n);
	}

	while(test_cases2--)
	{
		int temp_answer = calculate_factorial(factorial_table , mq.front());	
		mq.pop();;
		cout<< temp_answer << endl;
	}
	
	return 0;
}