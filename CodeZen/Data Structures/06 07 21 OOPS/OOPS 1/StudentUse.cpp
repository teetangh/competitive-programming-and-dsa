#include <iostream>
using namespace std;
#include "include/Student.hpp"

int main(int argc, char const *argv[])
{
    // Create Objects statically
    Student s1;
    Student s2;

    Student s3, s4, s5;

    s1.setAge(24, 123);
    s1.setrollNumber(101);

    cout << " S1 age " << s1.getAge() << endl;
    cout << " S1 Roll Number " << s1.getRollNumber() << endl;
    s1.display();

    s2.setAge(24, 123);
    s2.display();

    // Create Objects Dynamically
    Student *s6 = new Student;
    (*s6).setAge(25, 123);
    (*s6).setrollNumber(105);

    s6->setAge(25, 123);
    s6->setrollNumber(105);

    cout << s6->getAge() << endl;
    cout << s6->getRollNumber() << endl;
    s6->display();
    return 0;
}
