#include <iostream>
#include <list>
using namespace std;

int main()
{
    list<char> listObject1, listObject2, listObject3;
    int i;

    for (i = 0; i < 10; i += 2)
        listObject1.push_back(i + 'A');
    for (i = 1; i < 11; i += 2)
        listObject2.push_back(i + 'A');

    cout << "Contents of listObject1:\n";
    list<char>::iterator p = listObject1.begin();
    while (p != listObject1.end())
    {
        cout << *p << " ";
        p++;
    }

    cout << "\n\n";

    // auto p = listObject1.begin();
    // for (auto p = listObject1.begin(); p != listObject1.end(); p++)
    //     cout << *p << " ";

    cout << "Contents of listObject2:\n";
    p = listObject2.begin();
    while (p != listObject2.end())
    {
        cout << *p << " ";
        p++;
    }
    cout << "\n\n";

    listObject1.merge(listObject2); // now, merge the two lists
    if (listObject2.empty())
        cout << "listObject2 is now empty\n";

    cout << "Contents of listObject1 after merge:\n";
    p = listObject1.begin();
    while (p != listObject1.end())
    {
        cout << *p << " ";
        p++;
    }
    cout << "\n\n";

    char str[] = "-splicing-";
    for (i = 0; str[i]; i++)
        listObject3.push_back(str[i]);

    cout << "Contents of listObject3:\n";
    p = listObject3.begin();
    while (p != listObject3.end())
    {
        cout << *p << " ";
        p++;
    }
    cout << "\n\n";

    p = listObject1.begin();
    while (p != listObject1.end())
    {
        if (*p == 'F')
            listObject1.splice(p, listObject3);
        p++;
    }

    cout << "Contents of listObject1 after splice:\n";
    p = listObject1.begin();
    while (p != listObject1.end())
    {
        cout << *p << " ";
        p++;
    }

    return 0;
}
