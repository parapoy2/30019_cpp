#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n1 = 3, n2 = 5, n3 = 10;

    cout << "dla " << n1 << " przedmiotów: " << pow(2, n1) << " konfiguracji\n";
    cout << "dla " << n2 << " przedmiotów: " << pow(2, n2) << " konfiguracji\n";
    cout << "dla " << n3 << " przedmiotów: " << pow(2, n3) << " konfiguracji\n";
    cin.get();
    return 0;
}