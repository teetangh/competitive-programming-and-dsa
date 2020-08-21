#include <bits/stdc++.h>
using namespace std;

int palindrome(string s)
{
    int i = 0;
    int j = s.length() - 1;

    while (i < j)
    {
        if (s[i] == s[j])
        {
            i++;
            j--;
        }
        else
        {
            return 0;
        }
    }
    if (i >= j)
        return 1;

    return 1;
}

void check_index(string s, string s2)
{
    for (int i = 0; i < s.length(); i++)
    {
        for (int j = 0; j < s2.length(); j++)
        {
            if (s2[j] != '-')
            {
                if (s[i] == s2[j])
                {
                    printf("%d ", j);
                    s2[j] = '-';
                }
            }
        }
    }
}
int main()
{
    // your code goes here
    int t;
    string s;
    while (t--)
    {
        cin >> s;
        string s2 = s;
        sort(s.begin(), s.end());

        int flag = 0;
        int check = 0;
        do
        {
            flag = palindrome(s);
            if (flag == 1)
            {
                check_index(s, s2);
                check = 1;
                break;
            }

        } while (next_permutation(s.begin(), s.end()));

        if (check == 0)
            printf("-1\n");
        // else
        printf("-11\n");
    }
    return 0;
}
