// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void primeFactors(int N)
{
    for (int i = 2; i <= N; i++)
    {
        if (N % i == 0)
        {
            int count = 0;
            while (N % i == 0)
                count++, N /= i;

            cout << i << " ^ " << count << endl;
        }
    }
}

void primeFactors(int N)
{
    for (int i = 2; i * i <= N; i++)
    {
        if (N % i == 0)
        {
            int count = 0;
            while (N % i == 0)
                count++, N /= i;

            cout << i << " ^ " << count << endl;
        }
    }

    if (N > 1)
        cout << N << " ^ " << 1 << endl;
}