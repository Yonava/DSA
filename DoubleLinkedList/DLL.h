#pragma once
#include <string>
#include <iostream>

using namespace std;

struct Student {
    string name;
    string id;
    string phoneNum;
    string address;
    string pronouns;
};

struct Node {
    Node* prev;
    Node* next;
    Student* student;
};

class StudentLinkedList {

    private:
        Node* tail;
        Node* head;
        int length;

    public:
        StudentLinkedList(Student* student);
        ~StudentLinkedList();

        void insert(Student* student);
        void remove(int index);

        int getLength();

        void print();
};


