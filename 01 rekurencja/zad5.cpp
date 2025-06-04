#include <iostream>
using namespace std;


bool pierwsza(int n) {
	for (int i = 2; i < n; i++) {
		if (n % 2 == 0) {
			return false;
		}

	}
	return true;

}

void wyswietl(int j, int n) {
	if (n<j || n == 1) {
		return;
	}
	if (n % j == 0 && pierwsza(j)) {
		cout << j << " ";
		n /= j;
		j = 2;
		wyswietl(j, n);

	}
	else {
		wyswietl(j + 1, n);
	}
}

int main() {
	int n;
	cout << "Wprowadź liczbę: ";
	cin >> n;
	wyswietl(2, n);
}