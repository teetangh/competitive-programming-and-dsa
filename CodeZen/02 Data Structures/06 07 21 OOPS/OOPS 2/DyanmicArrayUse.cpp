#include <iostream>
#include "include/DynamicArray.hpp"
using namespace std;

int main(int argc, char const *argv[])
{
    DynamicArray d1;

    d1.add(10);
    d1.add(20);
    d1.add(30);
    d1.add(40);
    d1.add(50);
    d1.add(60);
    d1.add(70);

    d1.print();

    DynamicArray d2(d1); //AVOIDED Shallow Copy of Copy Constructor
                         //by overloading the copy constructor
    DynamicArray d3;
    d3 = d1; // AVOIDED Shallow Copy of Copy Assignment operator
             //by operator overloading of =
    d1.add(0, 100);
    d1.print();
    d2.print();
    d3.print();

    return 0;
}
