#include <iostream>
using namespace std;
#include "include/Student.hpp"

int main(int argc, char const *argv[])
{
    Student s1(10, 1001);
    Student s2(20, 2001);

    Student *s3 = new Student(30, 3001);
    s2 = s1;
    *s3 = s1;
    s2 = *s3;

    cout << " S1: " << endl;
    s1.display();
    cout << " S2: " << endl;
    s2.display();
    cout << " S3: " << endl;
    s3->display();

    delete s3;
}
