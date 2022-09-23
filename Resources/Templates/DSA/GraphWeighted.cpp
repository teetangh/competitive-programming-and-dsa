// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>

// Policy Based Data Structures
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template <typename T>
class DSU
{
    vector<T> parent;
    vector<T> rank;
};

template <typename T>
class GraphWeighted
{
private:
    T V;
    vector<vector<pair<T, T>>> adj;
    vector<T> visited;
    vector<T> colors;
    bool isDirected;

public:
};
