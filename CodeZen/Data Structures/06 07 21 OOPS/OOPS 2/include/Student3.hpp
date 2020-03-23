#include <iostream>
using namespace std;

class Student3
{
private:
public:
    int rollNumber;
    int age;
    static int totalStudents; // total no of students present

    Student3()
    {
        totalStudents++;
    }

    int getRollNumber()
    {
        return rollNumber;
    }

    // Static Functions can access only static data members(properties)
    // Static Functions cannot use this keywords
    static int getTotalStudent()
    {
        return totalStudents;
    }
};

int Student3::totalStudents = 0; // Initialise static Data memebers
