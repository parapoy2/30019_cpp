#include <iostream>
#include <vector>
using namespace std;

int ksDpTable(int weights[], int values[], int n, int capacity) {
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= capacity; ++w) {
            dp[i][w] = dp[i - 1][w]; 

            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);
            }
        }
    }

    return dp[n][capacity];
}

int main() {
    int weights[] = { 10, 20, 30 };
    int values[] = { 60, 100, 120 };
    int n = 3;
    int capacity = 50;

    cout << "weights: ";
    for (int i = 0; i < n; i++) cout << weights[i] << " ";

    cout << "\nvalues: ";
    for (int i = 0; i < n; i++) cout << values[i] << " ";

    cout << "\nmax weight capacity: " << capacity << endl;

    cout << "maximum value: " << ksDpTable(weights, values, n, capacity) << endl; 

    cin.get();
    return 0;
}
