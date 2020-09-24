#include <bits/stdc++.h>
using namespace std;

class kadane_triplet
{
public:
    int currentUp;
    int currentDown;
    int currentSum;

    kadane_triplet() { currentUp = currentDown = currentSum = 0; }

    kadane_triplet kadanes_algo_maximmum_sum_subarray(vector<int> &nums)
    {
        int maxStartIndex = 0;
        int maxEndIndex = 0;
        int maxSum = INT_MIN;

        int cumulativeSum = 0;
        int maxStartIndexUntilNow = 0;

        for (int currentIndex = 0; currentIndex < nums.size(); currentIndex++)
        {
            cumulativeSum += nums[currentIndex];
            if (cumulativeSum > maxSum)
            {
                maxSum = cumulativeSum;
                maxStartIndex = maxStartIndexUntilNow;
                maxEndIndex = currentIndex;
            }
            if (cumulativeSum < 0)
            {
                maxStartIndexUntilNow = currentIndex + 1;
                cumulativeSum = 0;
            }
        }

        // kadane_triplet object;
        // object.currentUp = maxStartIndex;
        // object.currentDown = maxEndIndex;
        // object.currentSum = maxSum;

        this->currentUp = maxStartIndex;
        this->currentDown = maxEndIndex;
        this->currentSum = maxSum;

        return *this;
    }
};

int maximum_sum_rectangle_optimized(vector<vector<int>> matrix)
{
    // int currentSubArraySum = 0;

    int maxUp = 0;
    int maxDown = 0;
    int maxLeft = 0;
    int maxRight = 0;

    int maxSubArraySum = INT_MIN;

    kadane_triplet object;

    for (int left = 0; left < matrix.size(); left++)
    {
        vector<int> nums(matrix.size(), 0);

        // std::copy(matrix[left].begin(), matrix[left].end(), nums);

        for (int right = left; right < matrix.size(); right++)
        {
            // std::transform(nums.begin(), nums.end(), matrix[left].begin() + right, nums.begin(), std::plus<int>());

            for (int x = 0; x < matrix.size(); x++)
                nums[x] += matrix[x][right];
            // cout << "=======================";
            // cout << endl;
            // for (auto &ele : nums)
            //     cout << ele << " ";
            // cout << endl;
            // cout << "=======================";

            object = object.kadanes_algo_maximmum_sum_subarray(nums);

            // cout << "=======================";
            // cout << object.currentUp << " " << object.currentDown << " " << object.currentSum << " " << maxSubArraySum << " " << endl;
            // cout << "=======================";

            if (object.currentSum >= maxSubArraySum)
            {
                maxUp = object.currentUp;
                maxDown = object.currentDown;
                maxLeft = left;
                maxRight = right;

                maxSubArraySum = object.currentSum;
            }
        }

        nums.clear();
    }

    return maxSubArraySum;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    int rows, columns;
    cin >> rows >> columns;

    // 2d array with rows x columns
    vector<vector<int>> matrix;
    matrix.resize(rows, vector<int>(columns, 0));

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            cin >> matrix[i][j];

    cout << maximum_sum_rectangle_optimized(matrix) << endl;

    return 0;
}

// // Sample IO
// 4 5
// 1 2 -1 -4 -20
// -8 -3 4 2 1
// 3 8 10 1 3
// -4 -1 1 7 -6

// 29