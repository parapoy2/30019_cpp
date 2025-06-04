#include <iostream>
using namespace std;

struct DNode {
    int data;
    DNode* prev;
    DNode* next;

    DNode(int val) : data(val), prev(nullptr), next(nullptr) {}
};

void pushFront(DNode*& head, int val) {
    DNode* newNode = new DNode(val);
    if (head) head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

void popBack(DNode*& head) {
    if (!head) return;
    DNode* temp = head;
    while (temp->next) temp = temp -> next;
    if (temp->prev) temp -> prev -> next = nullptr;
    else head = nullptr;
    delete temp;
}

void printList(DNode* head) {
    while (head) {
        cout << head->data << " <-> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    DNode* head = nullptr;

    pushFront(head, 30);
    pushFront(head, 20);
    pushFront(head, 10);

    cout << "Po dodaniu: ";
    printList(head);

    popBack(head);

    cout << "Po usunieciu z konca: ";
    printList(head);

    return 0;
}
