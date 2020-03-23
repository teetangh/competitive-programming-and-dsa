#include <iostream>
using namespace std;

class Student3
{
private:
public:
    int rollNumber;
    int age;
    static int totalStudents; // total no of students present

    // Student3(/* args */);
    // ~Student3();
};

int Student3::totalStudents = 0; // Initialise static Data memebers
