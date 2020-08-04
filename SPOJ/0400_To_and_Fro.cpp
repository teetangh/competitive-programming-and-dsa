#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;

string processed_string(pair<int, string> pis)
{
    // int jumbled_string_length = pis.second.length();
    // int meaningful_string_length = jumbled_string_length / pis.first;

    // vector<std::string> empty_strings_vector(pis.first);

    // for (int i = 0; i < pis.first; i++)
    //     for (int j = 0; j < meaningful_string_length; j++)
    //         empty_strings_vector[i] += ((pis.second)[(j * pis.first) + i]);

    // // for (int i = 0; i < meaningful_string_length; i++)
    // // {
    // //     for (int j = 0; j < pis.first; j++)
    // //     {

    // //     }
    // // }

    // std::string result;
    // for (auto &each_string : empty_strings_vector)
    //     cout << each_string << endl;
    // // result += each_string;

    // // return result;

    int cols = pis.first;
    int rows = pis.second.length() / pis.first;

    vector<string> vec(rows);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (i % 2 == 0)
                vec[i] += (pis.second)[(i * pis.first) + j];
            else
                vec[i] += (pis.second)[(i * pis.first) + (cols - j - 1)];
        }
    }

    std::string output;
    for (int j = 0; j < cols; j++)
    {
        for (int i = 0; i < rows; i++)
        {
            output += vec[i][j];
        }
    }

    return output;
}
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("input1.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);
#endif
    int current_strings_columns;
    string current_input_string;

    vector<pair<int, string>> vpis;
    queue<string> qs;

    cin >> current_strings_columns >> current_input_string;
    while (current_strings_columns != 0)
    {
        qs.push(processed_string(std::make_pair(current_strings_columns, current_input_string)));
        // qs.push(current_input_string);
        cin >> current_strings_columns >> current_input_string;
    }

    while (!qs.empty())
    {
        string temp = qs.front();
        qs.pop();
        cout << temp << endl;
    }

    return 0;
}
