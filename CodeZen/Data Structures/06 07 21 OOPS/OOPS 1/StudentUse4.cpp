#include <iostream>
using namespace std;
#include "Student.cpp"

int main(int argc, char const *argv[])
{
    cout << endl;
    Student s1(10, 1001);
    cout << " S1 : ";
    s1.display();

    Student s2(s1);
    cout << " s2 : ";
    s2.display();

    Student *s3 = new Student(20, 2001);
    cout << " s3 : ";
    s3->display();

    Student s4(*s3);

    Student *s5 = new Student(*s3);
    Student *s5 = new Student(s1);
}
