#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void printList(std::initializer_list<T> text)
{
    for (const auto &value : text)
        std::cout << value << " ";
    cout << endl;
}

template <typename T, typename U>
static inline void amax(T &x, U &y)
{
    if (x < y)
        x = y;
}
template <typename T, typename U>
static inline void amin(T &x, U &y)
{
    if (y < x)
        x = y;
}

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input1.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output1.txt", "w", stdout);
#endif

    vector<int> vec = {0, 1, 2, 3, 4};

    for (const auto &value : vec)
        cout << value << ' ';

    cout << endl;
    int array[] = {1, 2, 3, 4, 5};
    for (const auto &value : array)
        cout << value << " ";

    cout << endl;

    printList({"One", "Two", "Three"});

    int max_val = 0, min_val = 1e5;
    int array2[] = {4, -5, 6, -9, 2, 11};

    for (auto const &val : array2)
        amax(max_val, val), amin(min_val, val);

    std::cout << "Max value " << max_val << "\n"
              << "Min value " << min_val;

    return 0;
}
