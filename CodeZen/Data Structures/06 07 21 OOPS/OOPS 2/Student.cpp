#include <iostream>
#include <string.h>
using namespace std;

class Student
{
private:
    int age;

public:
    char *name;

public:
    // Regular Parameterized Constructor
    //  (obviously eliminates default constructor)
    Student(int age, char *name)
    {
        this->age = age;

        // Shallow Copy
        // this->name = name;

        // Deep Copy
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    // Copy Constructor
    // Student(Student s){}  //Infinite Loop Coopy Constructor
    Student(const Student &s)
    {
        this->age = s.age;
        // this->name = s.name;   // shallow copy

        // Deep Copy
        this->name = new char[strlen(s.name) + 1];
        strcpy(this->name, s.name);
    }

    void display()
    {
        cout << " Name is " << name << endl;
        cout << " Age is " << age << endl;
    }
    // ~Student();
};
