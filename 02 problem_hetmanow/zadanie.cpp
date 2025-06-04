#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace chrono;

/// queen
bool isSafe(vector<vector<int>>& board, int row, int col, int N) {
    for (int i = 0; i < col; i++) {
        if (board[row][i] == 1)
            return false;
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1)
            return false;
    }
    for (int i = row, j = col; i < N && j >= 0; i++, j--) {
        if (board[i][j] == 1)
            return false;
    }
    return true;
}

bool solveNQueens(vector<vector<int>>& board, int col, int N) {
    if (col >= N)
        return true;
    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col, N)) {
            board[i][col] = 1;
            if (solveNQueens(board, col + 1, N))
                return true;
            board[i][col] = 0;
        }
    }
    return false;
}

/// wieża
bool isSafeWieza(vector<vector<int>>& board, int wiersz, int kolumna, int N) {
    for (int i = 0; i < N; i++) {
        if (board[wiersz][i] == 1)
            return false;
    }
    for (int i = 0; i < N; i++) {
        if (board[i][kolumna] == 1)
            return false;
    }
    return true;
}

bool solveWieza(vector<vector<int>>& board, int wiersz, int N, int liczbaWiez) {
    if (liczbaWiez == 0)
        return true;
    if (wiersz >= N)
        return false;
    for (int kolumna = 0; kolumna < N; kolumna++) {
        if (isSafeWieza(board, wiersz, kolumna, N)) {
            board[wiersz][kolumna] = 1;
            if (solveWieza(board, wiersz + 1, N, liczbaWiez - 1))
                return true;
            board[wiersz][kolumna] = 0;
        }
    }
    return solveWieza(board, wiersz + 1, N, liczbaWiez);
}

void printBoard(vector<vector<int>>& board, int N) {
    for (const auto& row : board) {
        for (int cell : row) {
            cout << (cell ? "Q " : ". ");
        }
        cout << endl;
    }
}



int main() {
    int N = 3; 
    int numer, rozw;
    int liczbaWiez = N;

    cout << "1 - Queens, 2 - Wieza \n Podaj numer: ";
    cin >> numer;
    vector<vector<int>> board(N, vector<int>(N, 0));
    auto start = chrono::high_resolution_clock::now();

    if (numer == 1) {
        rozw = solveNQueens(board, 0, N);
    }
    else if (numer == 2) {
        cout << "Podaj liczbe wiez: ";
        cin >> liczbaWiez;
        rozw = solveWieza(board, 0, N, liczbaWiez);
    }
    else {
        cout << "Blad" << endl;
        return 1;
    }

    auto stop = chrono::high_resolution_clock::now();
    auto czas = chrono::duration_cast<chrono::milliseconds>(stop - start);

    if (rozw) {
        printBoard(board, N);
        cout << "Czas wykonania: " << czas.count() << endl;
    }
    else {
        cout << "niema rozwiazan" << endl;
    }

    return 0;
}