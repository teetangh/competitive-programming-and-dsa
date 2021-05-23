#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int reverse_number(int number)
{
	int rev = 0 ;
	int last_digit;
	while (number  > 0 )
	{
		last_digit = number % 10;
		rev = rev * 10 + last_digit;
		number = number / 10;
	}
	return rev;
}

int main()
{
	#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("xinput.txt" , "r", stdin);
	// for writing output to output.txt
	freopen("xoutput.txt", "w" , stdout);
	#endif

	int test_cases;
	cin >> test_cases;
	// cout << test_cases;

	queue <int> mq;

	while(test_cases--)
	{
		int num1 , num2 , rev_num1 , rev_num2;
		cin >> num1 >> num2;

		rev_num1 = reverse_number(num1);
		rev_num2 = reverse_number(num2);

		int answer = reverse_number(rev_num1 + rev_num2);
		mq.push(answer);
	}

	while(!mq.empty())
	{
		int temp = mq.front();
		mq.pop();
		cout << temp << endl;
	}

}