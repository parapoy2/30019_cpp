#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;
int licznikSwapow = 0;            
int licznikBinarnego = 0;         

void zamien(int& a, int& b) {
    licznikSwapow++;             
    int temp = a;
    a = b;
    b = temp;
}

int podziel(int tablica[], int lewy, int prawy) {
    int pivot = tablica[prawy];
    int i = lewy - 1;
    for (int j = lewy; j < prawy; j++) {
        if (tablica[j] < pivot) {
            i++;
            zamien(tablica[i], tablica[j]);
        }
    }
    zamien(tablica[i + 1], tablica[prawy]);
    return i + 1;
}

void quickSort(int tablica[], int lewy, int prawy) {
    if (lewy < prawy) {
        int pi = podziel(tablica, lewy, prawy);
        quickSort(tablica, lewy, pi - 1);
        quickSort(tablica, pi + 1, prawy);
    }
}

int wyszukiwanieBinarne(int tablica[], int lewy, int prawy, int liczba) {
    licznikBinarnego++;           
    if (lewy <= prawy) {
        int srodek = lewy + (prawy - lewy) / 2;
        if (tablica[srodek] == liczba)
            return srodek;
        else if (tablica[srodek] > liczba)
            return wyszukiwanieBinarne(tablica, lewy, srodek - 1, liczba);
        else
            return wyszukiwanieBinarne(tablica, srodek + 1, prawy, liczba);
    }
    return -1;
}

int main() {
    int n;
    cout << "Podaj dlugosc tablicy: ";
    cin >> n;

    int tablica[1000000]; 

    cout << "Wpisz " << n << " liczb:\n";
    for (int i = 0; i < n; i++) {
        cin >> tablica[i];
    }

    auto start_sort = high_resolution_clock::now();
    quickSort(tablica, 0, n - 1);
    auto end_sort = high_resolution_clock::now();
    auto czas_sortowania = duration_cast<microseconds>(end_sort - start_sort).count();

    cout << "\nPosortowana tablica:\n";
    for (int i = 0; i < n; i++) {
        cout << tablica[i] << " ";
    }
    cout << endl;

    int liczba;
    cout << "\nWpisz liczbe do wyszukania: ";
    cin >> liczba;

    auto start_szukania = high_resolution_clock::now();
    int indeks = wyszukiwanieBinarne(tablica, 0, n - 1, liczba);
    auto end_szukania = high_resolution_clock::now();
    auto czas_szukania = duration_cast<microseconds>(end_szukania - start_szukania).count();

    if (indeks != -1)
        cout << "Liczba znaleziona na indeksie: " << indeks << endl;
    else
        cout << "Liczba nie zostala znaleziona.\n";

    cout << "\nCzas sortowania: " << czas_sortowania << " mikrosekund\n";
    cout << "Czas wyszukiwania: " << czas_szukania << " mikrosekund\n";
    cout << "Liczba operacji zamiany (swap): " << licznikSwapow << endl;
    cout << "Liczba wywolan wyszukiwania binarnego: " << licznikBinarnego << endl;
    cout << "Czas laczny: " << (czas_sortowania + czas_szukania) << " mikrosekund\n";

    return 0;
}