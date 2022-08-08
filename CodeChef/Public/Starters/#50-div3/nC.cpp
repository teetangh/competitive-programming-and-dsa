// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

class Meeting
{
public:
    int start, end;
    Meeting(int start, int end)
    {
        this->start = start;
        this->end = end;
    }
};

bool compare(Meeting *m1, Meeting *m2)
{
    if (m1->start < m2->start)
        return true;
    else if (m1->start > m2->start)
        return false;
    else
        return m1->end <= m2->end;
}

int getMaxMeetings(vector<Meeting *> &meetings)
{

    sort(meetings.begin(), meetings.end(), compare);

    vector<int> startTimes;
    vector<int> endTimes;

    for (auto ele : meetings)
    {
        startTimes.push_back(ele->start);
        endTimes.push_back(ele->end);
    }

    int i = 0;
    int j = 0;

    int count = 1;
    int maxCount = INT_MIN;
    while (i < startTimes.size() && j < endTimes.size())
    {

        if (endTimes[i] < startTimes[j])
        {
            count++;
            if (count > maxCount)
                maxCount = count;
            i++;
        }
        else
        {
            count = 0;
            j++;
        }
    }

    return maxCount;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);   // for getting input from xinput.txt
    freopen("xoutput.txt", "w", stdout); // for writing output to xoutput.txt
#endif

    int tc;
    cin >> tc;

    while (tc--)
    {
        int n;
        cin >> n;

        vector<Meeting *> meetings;
        for (int i = 0; i < n; i++)
        {
            int start, end;
            cin >> start >> end;
            meetings.push_back(new Meeting(start, end));
        }

        cout << getMaxMeetings(meetings) << endl;
    }

    return 0;
}
