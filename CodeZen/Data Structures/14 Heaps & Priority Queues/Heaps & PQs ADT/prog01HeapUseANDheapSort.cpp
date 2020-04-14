#include <iostream>
#include "../include/PriorityQueue.hpp"
using namespace std;

int main(int argc, char const *argv[])
{
    PriorityQueue p;
    p.insert(100);
    p.insert(10);
    p.insert(15);
    p.insert(4);
    p.insert(17);
    p.insert(21);
    p.insert(67);

    cout << p.getSize() << endl;
    cout << p.getMin() << endl;

    // Actually HeapSort
    while (!p.isEmpty())
    {
        cout << p.CNremoveMin() << " ";
    }

    cout << endl;
    return 0;
}
