#include <iostream>
using namespace std;

int silnia (int n, int num = 1){
    if(n<=0){
        return num;
    }
    else{
        return silnia (n-1, n * num);
    }
}

int main(){
    int n;
    cout<<"Podaj liczbe: ";
    cin>>n;
    cout << "Silnia " << n << " wynosi: " << silnia(n) << endl;
}