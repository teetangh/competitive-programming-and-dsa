#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>

typedef long long ll;
typedef long long int lli;

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    lli test_cases, k, count;
    cin >> test_cases >> k;

    lli n;
    count = 0;

    while (test_cases--)
    {
        cin >> n;
        if (n % k == 0)
            count++;
    }
    cout << count;

    return 0;
}

/* GIVEN BY CODE CHEF*/
// // Note that this problem is for testing fast input-output.
// // We can use scanf, printf in C langauge, which are quite fast in general :)
// #include <bits/stdc++.h> 

// using namespace std;

// // Usually, you can use scanf/printf in C++.
// // However, if you want to use cin/cout, it is usually slow.
// // To make it faster. Use cin.tie(NULL) and set ios_base::sync_with_stdio(false)
// // See the below code for details.

// int main() {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);

// 	// Read the input n, k
// 	int n, k;
// 	cin >> n >> k;

// 	// ans denotes number of integers n divisible by k
// 	int ans = 0;

// 	for (int i = 0; i < n; i++) {
// 		int t;
// 		cin >> t;
		
// 		if (t % k == 0) {
// 			ans++;
// 		}		
// 	}

// 	// Print the ans.
// 	cout << ans << "\n";	
		
// 	return 0;
// }



// Input:
// 7 3
// 1
// 51
// 966369
// 7
// 9
// 999996
// 11

// Output:
// 4