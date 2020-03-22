#include <iostream>
using namespace std;
#include "Student.cpp"

int main(int argc, char const *argv[])
{
    // Create Objects statically
    Student s1;
    Student s2;

    Student s3, s4, s5;

    s1.age = 24;
    s1.rollNumber = 101;

    cout << s1.age << endl;
    cout << s1.rollNumber << endl;

    s2.age = 30;

    // Create Objects Dynamically
    Student *s6 = new Student;
    (*s6).age = 25;
    (*s6).rollNumber = 105;

    s6->age = 25;
    s6->rollNumber = 105;

    cout << s6->age << endl;
    cout << s6->rollNumber << endl;
    return 0;
}
