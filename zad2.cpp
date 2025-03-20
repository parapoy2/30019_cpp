#include <iostream>
using namespace std;

int fibonacci(int n) {
    if (n < 0) {
        return 1;
    }
    else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    cout << "10 liczb Fibonacci: ";
    for (int i = 0; i < 10; i++) {
        cout << fibonacci(i) << " ";
    }
    cout << "\n";
    int n;
   
    cout << "Podaj liczbe: ";
    cin >> n;
    n -= 1;
    cout << "n element Fibonacci " << n+1 << " wynosi: " << fibonacci(n) << endl;
}