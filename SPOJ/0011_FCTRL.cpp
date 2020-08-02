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

namespace prime_factorisation
{
	pair<int, int> count_twos_and_fives(int num)
	{
		int num_twos = 0;
		int num_fives = 0;

		int save_num = num;
		while (num % 2 == 0)
		{
			num_twos++;
			num /= 2;
		}

		num = save_num;
		while (num % 5 == 0)
		{
			num_fives++;
			num /= 5;
		}

		pair<int, int> temp_pair;

		temp_pair = std::make_pair(num_twos, num_fives);

		return temp_pair;
	}

	int count_zeros_at_end(int num)
	{
		cout << "Hello" << endl;
		pair<int, int> temp_pair = prime_factorisation::count_twos_and_fives(num);
		int factor_2 = temp_pair.first;
		int factor_5 = temp_pair.second;
		cout << factor_2 << factor_5 << endl;
		return std::min(factor_2, factor_5);
	}

} // namespace prime_factorisation

namespace brute_force
{
	int count_zeros_at_end(int num)
	{
		int zero_counter = 0;

		while (num > 0)
		{
			int last_digit = num % 10;
			if (last_digit != 0)
				return zero_counter;
			else
				zero_counter++;

			num = num / 10;
		}
		return zero_counter;
	}

	int factorial(int num)
	{
		int temp_product = 1;

		for (int i = 2; i <= num; ++i)
			temp_product *= i;

		return temp_product;
	}
} // namespace brute_force

int main()
{
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input1.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output1.txt", "w", stdout);
#endif

	int test_cases;
	// cin >> test_cases;
	// cout << test_cases;

	queue<int> mq;

	int n;
	while (test_cases--)
	{
		cin >> n;
		mq.push(n);
	}

	while (!mq.empty())
	{
		// int temp = brute_force::count_zeros_at_end(brute_force::factorial(mq.front()));
		int temp = prime_factorisation::count_zeros_at_end(mq.front());

		mq.pop();
		cout << temp << endl;
	}

	// int temp = prime_factorisation::count_zeros_at_end(100);
}