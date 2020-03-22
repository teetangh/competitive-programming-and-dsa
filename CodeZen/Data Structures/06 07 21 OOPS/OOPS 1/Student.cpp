#include <iostream>
using namespace std;

class Student
{
private:
    int age;
    int rollNumber;

public:
    // Default Constructor
    Student()
    {
        cout << "Default Constructor called" << endl;
    }
    Student(int rollNumber)
    {
        cout << "Parametrized Constructor called" << endl;
        cout << " this " << this << endl;
        this->rollNumber = rollNumber;
    }
    Student(int age, int rollNUmber)
    {
        cout << "Parametrized Constructor 2 called" << endl;
        cout << " this " << this << endl;
        this->age = age;
        this->rollNumber = rollNumber;
    }

    void display()
    {
        cout << " age is " << age << " rollnumber is " << rollNumber << endl;
    }

    int getAge()
    {
        return age;
    }
    int getRollNumber()
    {
        return rollNumber;
    }

    void setAge(int a, int password)
    {
        if (a < 0 || password != 123)
            return;
        age = a;
    }
    void setrollNumber(int r)
    {
        rollNumber = r;
    }
};
