#include <iostream>
using namespace std;

class Student
{
private:
    int age;
    int rollNumber;

public:
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
