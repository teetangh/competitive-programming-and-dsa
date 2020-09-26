// Check the logic again
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test_cases;
    cin >> test_cases;

    while (test_cases--)
    {
        int size;
        cin >> size;
        vector<int> skills(size);

        for (int i = 0; i < size; i++)
            cin >> skills[i];

        for (int i = 0; i < size - 1; i++)
            if (skills[i] > skills[i + 1])
                swap(skills[i], skills[i + 1]);

        bool flag = true;
        for (int i = 0; i < size - 1; i++)
            if (skills[i] > skills[i + 1])
            {
                flag = false;
                break;
            }
        if (flag == true)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        skills.clear();
    }

    return 0;
}
