#include <iostream>
using namespace std;
#include "include/Student.hpp"

int main(int argc, char const *argv[])
{
    // Statically
    Student s1;
    s1.display();
    cout << endl;

    Student s2;
    s2.display();
    cout << endl;

    // Dynamically
    Student *s3 = new Student;
    s3->display();
    cout << endl;

    // Statically
    cout << " Parameterized Constructor Demo" << endl;
    Student s4(10);
    s4.display();
    cout << endl;

    // Dynamically
    Student *s5 = new Student(15);
    s5->display();
    cout << endl;

    // Statically
    Student s6(20, 1002);
    s6.display();
    cout << endl;
}
