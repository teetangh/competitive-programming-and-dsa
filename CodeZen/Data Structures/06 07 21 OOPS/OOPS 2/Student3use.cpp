#include <iostream>
using namespace std;
#include "include/Student3.hpp"

int main(int argc, char const *argv[])
{
    Student3 s1;

    cout << s1.rollNumber << " " << s1.age << endl;
    cout << Student3 ::totalStudents << endl;
    return 0;
}
