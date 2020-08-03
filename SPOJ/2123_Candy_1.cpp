#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// int calculate_min_moves()
// {

// }

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif

	std::vector<std::vector<int>> my_vec;
	
	int block;
	cin >> block;

	while (block--)
	{
		int candy_packets;
		int counter = 0;
		while (candy_packets--)
		{
			cin >> candy_packets;
			my_vec[counter].push_back(candy_packets);
		}
		counter++;
	}

	for (auto &x : my_vec)
	{
		for (auto &y : x)
			cout << y << " ";
		cout << endl;
	}

	return 0;
}