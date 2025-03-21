#include <iostream>
using namespace std;

int liczbaWystaoien(int n, int cyfra) {
    if (n == 0) {
        return 0;
    }
    else if (n % 10 == cyfra) {
        return 1 + liczbaWystaoien(n / 10, cyfra);
    }
    else {
        return liczbaWystaoien(n / 10, cyfra);
    }
}
int main() {
    int n, cyfra;
    cout << "Podaj liczbe: ";
    cin >> n;
    cout << "Podaj cyfre: ";
    cin >> cyfra;
    cout << "cyfra " << cyfra << " wystepuje: " << liczbaWystaoien(abs(n), cyfra) << endl;
}

