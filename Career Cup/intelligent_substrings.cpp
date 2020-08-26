// There are two types of characters in a particular language: special and normal. A character is special if its value is 1 and normal if its value is 0. Given string s, return the longest substring of s that contains at most k normal characters. Whether a character is normal is determined by a 26-digit bit string named charValue. Each digit in charValue corresponds to a lowercase letter in the English alphabet.

// Example:

// s = 'abcde'

// alphabet = abcdefghijklmnopqrstuvwxyz

// charValue = 10101111111111111111111111

// For clarity, the alphabet is aligned with charValue below:

// alphabet = abcdefghijklmnopqrstuvwxyz

// charValue = 10101111111111111111111111

// The only normal characters in the language (according to charValue) are b and d. The string s contains both of these characters. For k = 2, the longest substring of s that contains at most k = 2 normal characters is 5 characters long, abcde, so the return value is 5. If k = 1 instead, then the possible substrings are ['b', 'd', 'ab', 'bc', 'cd', 'de', 'abc', 'cde']. The longest substrings are 3 characters long, which would mean a return value of 3.

#include <iostream>
#include <climits>
#include <bits/stdc++.h>

using namespace std;

int getSpecialSubstring(string s, int k, string charValue)
{
	// Creating the Set
	set<char> normal_character_set;
	normal_character_set.clear();

	// Inserting the normal character into set
	for (int i = 0; i < charValue.size(); ++i)
	{
		if (charValue[i] != '1')
			normal_character_set.insert('a' + i);
	}

	int max_substring_size = INT_MIN;
	int lower_limit;
	int higher_limit;
	int current_window_normal_character_count;

	// i = current window length
	for (int i = s.size(); i > 0; i--)
	{
		lower_limit = 0;
		higher_limit = i - 1;
		while (higher_limit < s.size())
		{
			current_window_normal_character_count = 0;

			for (int j = lower_limit; j <= higher_limit; ++j)
			{
				if (normal_character_set.find(s[j]) != normal_character_set.end())
					current_window_normal_character_count++;
			}

			if (current_window_normal_character_count <= k && max_substring_size < i)
				return i;

			lower_limit++;
			higher_limit++;
		}
	}

	return max_substring_size;
}

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("xinput.txt", "r", stdin);
	freopen("xoutput.txt", "w", stdout);
#endif

	int test_cases;
	cin >> test_cases;

	string s, charValue;
	int k;

	while (test_cases--)
	{
		cin >> s;
		cin >> k;
		cin >> charValue;
		cout << getSpecialSubstring(s, k, charValue) << endl;
	}
	return 0;
}

// // Sample IO
// 2

// abcde                          
// 2                              
// 10101111111111111111111111     

// giraffe
// 2
// 01111001111111111011111111

// 5
// 3
