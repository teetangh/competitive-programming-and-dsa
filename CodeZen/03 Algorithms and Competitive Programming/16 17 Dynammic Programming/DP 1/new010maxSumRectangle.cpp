#include <bits/stdc++.h>
using namespace std;

class kadane_triplet
{
public:
    int currentUp;
    int currentDown;
    int currentSum;

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
    int maxUp;
    int maxDown;

    for (int left = 0; left < matrix[0].size(); left++)
    {
        vector<int> nums(matrix.size());
        for (int right = left; right < matrix[0].size(); right++)
        {
        }
    }
}

int main()
{
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