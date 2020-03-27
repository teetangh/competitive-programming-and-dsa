#include <iostream>
using namespace std;
#include "../include/CNLinkedList.hpp"

node *swap_nodes(node *head, int i, int j)
{
    //write your code here
    

}

int main()
{
    int i, j;
    node *head = takeinput();
    cin >> i;
    cin >> j;
    head = swap_nodes(head, i, j);
    print(head);
    return 0;
}
