#include <bits/stdc++.h>
using namespace std;
#define NEGINF -1e9

class city
{
public:
    int X;
    int Y;
    int F;

    float distance(const city &C2)
    {
        return sqrt((pow((C2.X - this->X), 2) + pow((C2.Y - this->Y), 2)));
    }
};

float max_happiness(vector<city> cities)
{
    vector<float> dp(cities.size() + 1, NEGINF);

    dp[0] = 0;
    dp[1] = cities[0].F;

    for (int i = 2; i < cities.size() + 1; i++)
    {
        auto desitination_city = cities[i];

        float max_happiness_value = INT_MIN;

        for (int j = i; j >= 1; j--)
        {
            auto current_city = cities[j];
            float current_happiness = desitination_city.F - current_city.distance(desitination_city);

            // // DEBUG
            // cout << i << " " << j << " " << current_happiness << " " << endl;

            if (current_happiness > max_happiness_value)
                max_happiness_value = current_happiness;
        }
        dp[i] = max_happiness_value;
    }
    // // DEBUG
    // cout << "==============" << endl;

    // // DEBUG
    // for (auto &ele : dp)
    //     cout << ele << " ";
    // cout << endl;

    return dp[cities.size()];
}

int main()
{

    int N;
    cin >> N;

    vector<city> cities(N);

    for (int i = 0; i < N; i++)
        cin >> cities[i].X >> cities[i].Y >> cities[i].F;

    cout << max_happiness(cities) << endl;
}