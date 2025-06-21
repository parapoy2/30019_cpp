#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    vector<int> wagi = { 4, 2, 3 };
    vector<int> wartosci = { 10, 4, 7 };
    int maxWaga = 5;
    int n = wagi.size();

    int najlepszaWartosc = 0;
    vector<int> najlepszaKombinacja(n, 0);

    int konfiguracji = pow(2, n);
    for (int maska = 0; maska < konfiguracji; ++maska) {
        int sumaWagi = 0, sumaWartosci = 0;
        vector<int> kombinacja(n, 0);

        for (int i = 0; i < n; ++i) {
            if (maska & (1 << i)) {
                sumaWagi += wagi[i];
                sumaWartosci += wartosci[i];
                kombinacja[i] = 1;
            }
        }

        cout << "kombinacja: ";
        for (int k : kombinacja) cout << k << " ";
        cout << "waga: " << sumaWagi << " wartosc: " << sumaWartosci << endl;

        if (sumaWagi <= maxWaga && sumaWartosci > najlepszaWartosc) {
            najlepszaWartosc = sumaWartosci;
            najlepszaKombinacja = kombinacja;
        }
    }

    cout << "najlepsza kombinacja: ";
    for (int k : najlepszaKombinacja) cout << k << " ";
    cout << "wartosc: " << najlepszaWartosc << endl;
    cin.get();
    return 0;
}