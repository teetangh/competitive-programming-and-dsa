#include <iostream>
using namespace std;
#include "Student.cpp"

int main()
{
    char name[] = "abcd";
    Student s1(20, name);
    s1.display();

    Student s2(s1);
    s2.name[0] = 'x';
    s2.display();
    s1.display();   //Shallow Copy constructor
}