#include <bits/stdc++.h>
using namespace std;

int main() {
    char arr[50][50];
    int rows = 0, cols = 0;

    // read 2D array until empty line
    while (true) {
        string temp;
        getline(cin, temp);
        if (temp.empty()) break;

        stringstream ss(temp);
        cols = 0;
        char c;
        while (ss >> c)
            arr[rows][cols++] = c;
        rows++;
    }

    // read the required word
    string required;
    cin >> required;

    // horizontal search
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j + required.size() <= cols; j++) {
            bool found = true;
            for (int k = 0; k < required.size(); k++) {
                if (arr[i][j + k] != required[k]) {
                    found = false;
                    break;
                }
            }
            if (found) { cout << "YES"; return 0; }
        }
    }

    // vertical search
    for (int j = 0; j < cols; j++) {
        for (int i = 0; i + required.size() <= rows; i++) {
            bool found = true;
            for (int k = 0; k < required.size(); k++) {
                if (arr[i + k][j] != required[k]) {
                    found = false;
                    break;
                }
            }
            if (found) { cout << "YES"; return 0; }
        }
    }

    cout << "NO";
    return 0;
}
