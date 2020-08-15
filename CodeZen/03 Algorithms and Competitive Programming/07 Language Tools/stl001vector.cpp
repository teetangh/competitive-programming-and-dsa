// Container Concepts
// Container
// SequenceContainer
// AssociativeContainer
// UnorderedAssociativeContainer
// Compare
// Red-black tree
// Sequence Containers
//     std::array
//     std::vector
//     std::deque
//     std::forward_list
//     std::list
// Container Adapters
//     std::stack
//     std::queue
//     std::priority_queue
// Associative Containers
//     std::set
//     std::map
//     std::multiset
//     std::multimap
// Unordered Associative Containers
//     std::unordered_set
//     std::unordered_multiset
//     std::unordered_map
//     std::unordered_multimap

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    vector<int> v(5);
    vector<int>::iterator it;

    for (int i = 0; i < v.size(); i++)
        v[i] = i + 1;

    for (it = v.begin(); it != v.end(); it++)
        cout << *it << " ";

    cout << endl;

    vector<int> v2;
    vector<int>::iterator it2;

    for (int i = 0; i < 5; i++)
        v2.push_back(i);

    for (it2 = v2.begin(); it2 != v2.end(); it2++)
        cout << *it2 << " ";

    return 0;
}

// // Sample io
// 1 2 3 4 5
// 0 1 2 3 4