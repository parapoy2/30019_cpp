#include <iostream>
#include <string>

using namespace std;

const int MAX = 100;
const string queueEmptyInfo = "Queue is empty.";

class Queue {
    int arr[MAX];
    int first = 0;
    int last = 0;

public:
    bool isEmpty() {
        return first == last;
    }

    bool isFull() {
        return last == MAX;
    }

    void enqueue(int x) {
        arr[last++] = x;
    }

    int dequeue() {
        return arr[first++];
    }

    int peek() {
        return arr[first];
    }

    int countElements() {
        return last - first;
    }

    void printQueue() {
        for (int i = first; i < last; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q;

    cout << "pusta? ";
    if (q.isEmpty()) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "pierwszy element: " << q.peek() << endl;
    cout << "usuniety: " << q.dequeue() << endl;
    cout << "pierwszy teraz: " << q.peek() << endl << endl;

    cout << "generowanie kolejki: \n";
    int n;
    cout << "podaj ilosc elementow ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        q.enqueue(rand() % 100);
    }

    cout << "elementow w kolejce: " << q.countElements() << endl;
    cout << "wartosc kolejki: ";
    q.printQueue();

    return 0;
}