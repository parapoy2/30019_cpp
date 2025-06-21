#include <iostream>
#include <vector>
#include <climits>
using namespace std;
 
int minMultRec(vector<int>& arr, int i, int j) {
    if (i + 1 == j)
        return 0;
 
    int res = INT_MAX;
 
    for (int k = i + 1; k < j; k++) {
        int curr = minMultRec(arr, i, k) + minMultRec(arr, k, j) + arr[i] * arr[k] * arr[j];
 
        res = min(curr, res);
    }
 
    return res;
}
 
int matrixMultiplication(vector<int>& arr) {
 
    int n = arr.size();
    return minMultRec(arr, 0, n - 1);
}
 
///prz/////////////////////////////////////
 
int minMultRecMemo(vector<int>& arr, int i, int j, vector<vector<int>>& memo) {
 
    if (i + 1 == j)
        return 0;
    if (memo[i][j] != -1)
        return memo[i][j];
 
    int res = INT_MAX;
 
    for (int k = i + 1; k < j; k++) {
        int curr = minMultRecMemo(arr, i, k, memo) + minMultRecMemo(arr, k, j, memo) + arr[i] * arr[k] * arr[j];
        res = min(curr, res);
    }
 
    memo[i][j] = res;
    return res;
}
 
int main() {
    cout <<  " Weryfikacja przykladu z instrukcji " << endl;
    vector<int> arr = { 10, 100, 5, 50 };
 
    int n = arr.size();
 
    cout << "Liczba macierzy: " << n - 1 << endl;
    cout << "Rozmiary macierzy:" << endl;
 
    for (int i = 0; i < n - 1; i++) {
        cout << "Macierz " << i + 1 << ": " << arr[i] << " x " << arr[i + 1] << endl;
    }
 
    //rec
    int resRec = matrixMultiplication(arr);
 
    cout << "Wynik (rekurencja): " << resRec << endl;
 
 
    //mem
    vector<vector<int>> memo(n, vector<int>(n, -1));
 
    int resMemo = minMultRecMemo(arr, 0, n - 1, memo);
 
    cout << "Wynik (memoizacja): " << resMemo << endl;
    return 0;
 
 
   


 
  
}