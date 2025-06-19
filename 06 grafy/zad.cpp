#include <iostream>
#include <vector>
#include <string>
using namespace std;

class GraphMatrix {
private:
    vector<vector<int>> graphMatrix;
    vector<string> vertexNames;
    int verticesNumber;

public:
    GraphMatrix(int vertices) {
        verticesNumber = vertices;
        graphMatrix.resize(vertices, vector<int>(vertices, 0));
        vertexNames.resize(vertices);
    }

    void setVertexName(int index, string name) {
        vertexNames[index] = name;
    }

    void addEdge(int i, int j) {
        graphMatrix[i][j] = 1;
        graphMatrix[j][i] = 1;
    }

    void print() {
        cout << "   ";
        for (int i = 0; i < verticesNumber; ++i) {
            cout << vertexNames[i] << " ";
        }
        cout << "\n";
        for (int i = 0; i < verticesNumber; ++i) {
            cout << vertexNames[i] << " ";
            for (int j = 0; j < verticesNumber; ++j) {
                cout << graphMatrix[i][j] << " ";
            }
            cout << "\n";
        }
    }
};

class GraphList {
private:
    vector<vector<int>> graphList;
    vector<string> vertexNames;

public:
    GraphList(int vertices) {
        graphList.resize(vertices);
        vertexNames.resize(vertices);
    }

    void setVertexName(int index, string name) {
        vertexNames[index] = name;
    }

    void addEdge(int u, int v) {
        graphList[u].push_back(v);
        graphList[v].push_back(u);
    }

    void print() {
        for (int i = 0; i < graphList.size(); ++i) {
            cout << vertexNames[i] << ": ";
            for (int neighbor : graphList[i]) {
                cout << vertexNames[neighbor] << " ";
            }
            cout << "\n";
        }
    }
};

int main() {
    int choice;
    int n;

    cout << "Wybierz typ grafu:\n";
    cout << "1 - Macierz sasiedztwa (GraphMatrix)\n";
    cout << "2 - Lista sasiedztwa (GraphList)\n";
    cin >> choice;

    cout << "Podaj liczbe wierzcholkow: ";
    cin >> n;

    vector<string> names(n);
    cout << "Podaj nazwy wierzcholkow:\n";
    for (int i = 0; i < n; ++i) {
        cin >> names[i];
    }

    if (choice == 1) {
        GraphMatrix gm(n);
        for (int i = 0; i < n; ++i) {
            gm.setVertexName(i, names[i]);
        }

        cout << "Podaj krawedzie (np. A B). Wpisz STOP aby zakonczyc:\n";
        while (true) {
            string uName, vName;
            cin >> uName;
            if (uName == "STOP") break;
            cin >> vName;

            int u = -1, v = -1;
            for (int i = 0; i < n; ++i) {
                if (names[i] == uName) u = i;
                if (names[i] == vName) v = i;
            }

            if (u != -1 && v != -1) {
                gm.addEdge(u, v);
            }
            else {
                cout << "Nieprawidlowe nazwy!\n";
            }
        }

        cout << "Macierz sasiedztwa:\n";
        gm.print();

    }
    else if (choice == 2) {
        GraphList gl(n);
        for (int i = 0; i < n; ++i) {
            gl.setVertexName(i, names[i]);
        }

        cout << "Podaj krawedzie (np. A B). Wpisz STOP aby zakonczyc:\n";
        while (true) {
            string uName, vName;
            cin >> uName;
            if (uName == "STOP") break;
            cin >> vName;

            int u = -1, v = -1;
            for (int i = 0; i < n; ++i) {
                if (names[i] == uName) u = i;
                if (names[i] == vName) v = i;
            }

            if (u != -1 && v != -1) {
                gl.addEdge(u, v);
            }
            else {
                cout << "Nieprawidlowe nazwy!\n";
            }
        }

        cout << "Lista sasiedztwa:\n";
        gl.print();

    }
    else {
        cout << "Niepoprawny wybor!\n";
    }

    system("pause");
    return 0;
}