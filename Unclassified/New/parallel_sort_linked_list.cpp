// Design a concurrently sorted linked list

#include <bits/stdc++.h>
#include <mutex>
#include <thread>
#include <condition_variable>
#include <atomic>
#include <chrono>

using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node(int val) : val(val), next(nullptr) {}
};

class SortedList
{
private:
    Node *head;
    mutex mtx;
    condition_variable cv;
    atomic<bool> flag;

public:
    SortedList() : head(nullptr), flag(false) {}

    void insert(int val)
    {
        unique_lock<mutex> lock(mtx);
        Node *node = new Node(val);
        if (head == nullptr)
        {
            head = node;
            return;
        }
        Node *prev = nullptr;
        Node *curr = head;
        while (curr != nullptr && curr->val < val)
        {
            prev = curr;
            curr = curr->next;
        }
        if (prev == nullptr)
        {
            node->next = head;
            head = node;
        }
        else
        {
            prev->next = node;
            node->next = curr;
        }
    }

    void sort()
    {
        unique_lock<mutex> lock(mtx);
        flag = true;
        cv.notify_all();
    }

    void print()
    {
        unique_lock<mutex> lock(mtx);
        while (!flag)
        {
            cv.wait(lock);
        }
        Node *curr = head;
        while (curr != nullptr)
        {
            cout << curr->val << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};

int main()
{
    SortedList list;
    thread t1([&list]()
              {
        for (int i = 0; i < 10; i++) {
            list.insert(i);
            this_thread::sleep_for(chrono::milliseconds(100));
        } });
    thread t2([&list]()
              {
        for (int i = 10; i < 20; i++) {
            list.insert(i);
            this_thread::sleep_for(chrono::milliseconds(100));
        } });
    thread t3([&list]()
              {
        for (int i = 20; i < 30; i++) {
            list.insert(i);
            this_thread::sleep_for(chrono::milliseconds(100));
        } });
    thread t4([&list]()
              {
        for (int i = 30; i < 40; i++) {
            list.insert(i);
            this_thread::sleep_for(chrono::milliseconds(100));
        } });
    thread t5([&list]()
              {
        for (int i = 40; i < 50; i++) {
            list.insert(i);
            this_thread::sleep_for(chrono::milliseconds(100));
        } });
    thread t6([&list]()
              {
        for (int i = 50; i < 60; i++) {
            list.insert(i);
            this_thread::sleep_for(chrono::milliseconds(100));
        } });
    thread t7([&list]()
              {
        for (int i = 60; i < 70; i++) {
            list.insert(i);
            this_thread::sleep_for(chrono::milliseconds(100));
        } });
    thread t8([&list]()
              {
        for (int i = 70; i < 80; i++) {
            list.insert(i);
            this_thread::sleep_for(chrono::milliseconds(100));
        } });
    thread t9([&list]()
              {
        for (int i = 80; i < 90; i++) {
            list.insert(i);
            this_thread::sleep_for(chrono::milliseconds(100));
        } });
    thread t10([&list]()
               {
        for (int i = 90; i < 100; i++) {
            list.insert(i);
            this_thread::sleep_for(chrono::milliseconds(100));
        } });
    thread t11([&list]()
               { list.sort(); });
    thread t12([&list]()
               { list.print(); });
    t1.join();
    t2.join();
    t3.join();

    t4.join();
    t5.join();
    t6.join();

    t7.join();
    t8.join();
    t9.join();

    t10.join();
    t11.join();
    t12.join();

    return 0;
}

// use g++ instead of gcc
//  g++ -std=c++11 -pthread temp.cpp
//  ./a.out