#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void pushFront(Node*& head, int value) {
    Node* newNode = new Node{ value, head };
    head = newNode;
}

void pushBack(Node*& head, int value) {
    Node* newNode = new Node{ value, nullptr };
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}

void popFront(Node*& head) {
    if (!head) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}

void popBack(Node*& head) {
    if (!head) return;
    if (!head->next) {
        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;
    while (temp->next->next)
        temp = temp->next;
    delete temp->next;
    temp->next = nullptr;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}







int countNodes(Node* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}


Node* findNode(Node* head, int value) {
    while (head) {
        if (head->data == value)
            return head;
        head = head->next;
    }
    return nullptr;
}


int main() {
    srand(time(0)); 
    Node* head = nullptr;

    pushFront(head, 10);
    pushBack(head, 20);
    pushFront(head, 5);
    cout << "Po dodaniu elementow: ";
    printList(head);

    popFront(head);
    popBack(head);
    cout << "Po usunieciach: ";
    printList(head);

    int n;
    cout << "Podaj liczbe wezlow: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        pushBack(head, rand() % 100); 
    }

    cout << "Lista z losowymi wartosciami: ";
    printList(head);

    int counted = countNodes(head);
    cout << "Liczba wezlow: " << counted << endl;

    int target;
    cout << "Podaj wartosc do wyszukania: ";
    cin >> target;
    Node* found = findNode(head, target);
    if (found)
        cout << "Znaleziono adres wezla: " << found << endl;
    else
        cout << "Nie znaleziono wartosci w liscie." << endl;

    return 0;
}
