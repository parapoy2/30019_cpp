#include <iostream>
#include <string>

using namespace std;

const int MAX = 100;
const string stackEmptyInfo = "Stack is empty.";

class Stack {
    int arr[MAX];
    int top = -1;

public:
    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX - 1;
    }

    void push(int x) {
        if (isFull()) {
            return;
        }
        arr[++top] = x;
    }

    int pop() {
        return arr[top--];
    }

    int peek() {
        return arr[top];
    }

    int countElements() {
        return top + 1;
    }

    void printStack() {
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack s;

    cout << "pusty? ";
    if (s.isEmpty()) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "gorny element: " << s.peek() << endl;
    cout << "usuniety: " << s.pop() << endl;
    cout << "gorny: " << s.peek() << endl << endl;

    cout << "generowanie stosu: \n";
    int n;
    cout << "podaj ilisc elementow ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        s.push(rand() % 100);
    }

    cout << "elementow w stosie: " << s.countElements() << endl;
    cout << "wartosc stosu: ";
    s.printStack();

   
    return 0;
}