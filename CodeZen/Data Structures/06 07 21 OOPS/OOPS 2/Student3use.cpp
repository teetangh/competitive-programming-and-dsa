#include <iostream>
using namespace std;
#include "include/Student3.hpp"

int main(int argc, char const *argv[])
{
    Student3 s1;

    // Demo 1

    // cout << s1.rollNumber << " " << s1.age << endl;
    // cout << s1.totalStudents << endl;

    // s1.totalStudents = 20;

    // Student3 s2;
    // cout << s2.totalStudents << endl;

    // Demo 2

    Student3 s2;
    Student3 s3, s4, s5;

    cout << Student3 ::totalStudents << endl;
    cout << Student3 ::getTotalStudent() << endl;
    // cout << Student3 ::getRollNumber() << endl;
    return 0;
}
