#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};


void pushBack(Node*& head, int value) {
    Node* newNode = new Node{ value, nullptr };

    if (!head) {
        head = newNode;
        newNode->next = head;      
        return;
    }

    Node* temp = head;
    while (temp->next != head)     
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;           
}


void popFront(Node*& head) {
    if (!head) return;

    if (head->next == head) {
        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;
    Node* tail = head;

    while (tail->next != head)
        tail = tail->next;

    head = head->next;
    tail->next = head;
    delete temp;
}




void printCyclicList(Node* head) {
    Node* temp = head;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
}






int main() {
    Node* head = nullptr;

    pushBack(head, 10);
    pushBack(head, 20);
    pushBack(head, 30);

    cout << "Po dodaniu elementow: ";
    printCyclicList(head);
    cout << "\n";

    popFront(head);      

    cout << "Po usunieciu pierwszego: ";
    printCyclicList(head); 


    return 0;
}