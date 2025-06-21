#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Przedmiot {
    int waga;
    int wartosc;
    double ratio;
};

bool compare(Przedmiot a, Przedmiot b) {
    return a.ratio > b.ratio;
}

int main() {
    vector<Przedmiot> przedmioty = {
        {4, 10}, {2, 4}, {3, 7}
    };
    int maxWaga = 5;

    for (auto& p : przedmioty) p.ratio = (double)p.wartosc / p.waga;
    sort(przedmioty.begin(), przedmioty.end(), compare);

    double lacznaWartosc = 0.0;
    int wagaZajeta = 0;

    for (auto p : przedmioty) {
        if (wagaZajeta + p.waga <= maxWaga) {
            wagaZajeta += p.waga;
            lacznaWartosc += p.wartosc;
            cout << "pelny: waga " << p.waga << " wartosc " << p.wartosc << endl;
        }
        else {
            int pozostalaWaga = maxWaga - wagaZajeta;
            lacznaWartosc += p.ratio * pozostalaWaga;
            cout << "czesc: waga " << pozostalaWaga << " wartosc " << p.ratio * pozostalaWaga << endl;
            break;
        }
    }

    cout << "laczna wartosc: " << lacznaWartosc << endl;
    cin.get();
    return 0;
}