#include <iostream>
#include <bits/stdc++.h>

#define DUMMY 9999

using namespace std;

void printVOV(vector<vector<int>> my_vec)
{
	for (auto &vec : my_vec)
	{
		for (auto &ele : vec)
		{
			cout << ele << " ";
		}
		cout << endl;
	}
}

vector<int> SubtractVectors(vector<int> v1, vector<int> v2)
{
	vector<int> temp_diff_vec;
	for (int i = 0; i < v1.size(); i++)
		temp_diff_vec.push_back(v1[i] - v2[i]);

	return temp_diff_vec;
}

queue<int> calculate_min_moves(vector<vector<int>> my_vec)
{
	queue<int> mq;
	for (auto &vec : my_vec)
	{
		if (vec[0] == DUMMY)
		{
			mq.push(0);
			continue;
		}

		int vec_sum = accumulate(vec.begin(), vec.end(), 0);

		float desired_candy_count = (float)vec_sum / (vec.size());

		if ((desired_candy_count) - int(desired_candy_count) != 0)
		{
			mq.push(-1);
			continue;
		}

		vector<int> desired_vec(vec.size());
		std::fill(desired_vec.begin(), desired_vec.end(), desired_candy_count);

		int moves_req_current_box = 0;
		auto diff_vector = SubtractVectors(desired_vec, vec);

		for (auto &ele : diff_vector)
			moves_req_current_box += abs(ele);

		moves_req_current_box /= 2;
		mq.push(moves_req_current_box);
	}
	return mq;
}

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif

	int block_size;
	cin >> block_size;

	vector<int> vec;
	vector<vector<int>> my_vec;
	int n;

	while (block_size != -1)
	{
		vec.clear();
		if (block_size == 0)
		{
			vec.push_back(DUMMY);
			my_vec.push_back(vec);

			cin >> block_size;
			continue;
		}
		while (block_size--)
		{
			cin >> n;
			vec.push_back(n);
		}
		my_vec.push_back(vec);
		cin >> block_size;
	}
	queue<int> mq = calculate_min_moves(my_vec);

	while (!mq.empty())
	{
		int temp = mq.front();
		mq.pop();
		cout << temp << endl;
	}

	return 0;
}