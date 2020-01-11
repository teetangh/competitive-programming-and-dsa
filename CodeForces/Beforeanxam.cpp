#include <iostream>
using namespace std;

int main()
{
    int d, sumTime;
    cin >> d >> sumTime;

    int input[30][2];

    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < 2; j++)
            cin >> input[i][j];
    }

    int minSum = 0;
    int maxSum = 0;

    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (j == 0)
                minSum += input[i][0];
            else
                maxSum += input[i][1];
        }
    }

    // cout << "minSum: " << minSum << endl;
    // cout << "maxSum: " << maxSum << endl;

    int *output = (int *)calloc(d, sizeof(int));
    int tempSum = sumTime;
    int tempDay = 0;
    int lastOne = 0;

    if (minSum > sumTime || maxSum < sumTime)
        cout << "NO" << endl;
    else
    {
        cout << "YES" << endl;
        int i;

        for (i = 0; i < d; i++)
        {
            tempDay = input[i][1];
            if (tempSum - tempDay > 0)
            {
                // cout << "debug1" << endl;
                tempSum -= tempDay;
            }
            else
            {
                // cout << "debug2" << endl;
                lastOne = tempSum;
            }

            // cout << "tempDay " << tempDay << endl;
            // cout << "tempSum " << tempSum << endl;
            // cout << "lastOne " << lastOne << endl;

            if (input[i][0] <= tempDay && tempDay >= input[i][1] && (tempSum >= 0 || lastOne > 0))
            {
                if (tempSum - tempDay < 0 && lastOne >= 0)
                {
                    // cout << "debug3" << endl;
                    output[i] = lastOne;
                    break;
                }
                else
                {

                    // cout << "debug4" << endl;
                    output[i] = tempDay;
                }
            }
        }

        for (i = 0; i < d; i++)
            cout << output[i] << ' ';
        // fp
    }
}
