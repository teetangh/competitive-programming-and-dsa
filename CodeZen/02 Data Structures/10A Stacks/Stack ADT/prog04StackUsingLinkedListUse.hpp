#include <iostream>
#include "../include/StackUsingLinkedList.hpp"
using namespace std;

int main()
{

    Stack<int> st;

    int choice;
    cin >> choice;
    int input;

    while (choice != -1)
    {
        if (choice == 1)
        {
            cin >> input;
            st.push(input);
        }
        else if (choice == 2)
        {
            int ans = st.pop();
            if (ans != 0)
            {
                cout << ans << endl;
            }
            else
            {
                cout << "-1" << endl;
            }
        }
        else if (choice == 3)
        {
            int ans = st.top();
            if (ans != 0)
            {
                cout << ans << endl;
            }
            else
            {
                cout << "-1" << endl;
            }
        }
        else if (choice == 4)
        {
            cout << st.getSize() << endl;
        }
        else if (choice == 5)
        {
            cout << st.isEmpty() << endl;
        }
        cin >> choice;
    }
}
