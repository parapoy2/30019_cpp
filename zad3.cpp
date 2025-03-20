#include <iostream>
using namespace std;

int sumaCyfr(int n) {
    if (n == 0) 
        return 0;
    
    else 
        return n % 10 + sumaCyfr (n / 10);
    
}

int main() {
    int n;
    cout << "Podaj liczbe: ";
    cin >> n;
    cout << "Suma cyfr " << n << " wynosi: " << sumaCyfr(n) << endl;
}  