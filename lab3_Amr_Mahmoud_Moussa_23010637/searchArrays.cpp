#include <bits/stdc++.h>
using namespace std;

class SearchArrays {
private:

    int grid[50][50];
    bool visited[50][50];
    int rows, cols;
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    void dfs(int r, int c) {
        if (r < 0 || r >= rows || c < 0 || c >= cols) return;
        if (visited[r][c] || grid[r][c] == 0) return;

        visited[r][c] = true;

        for (int k = 0; k < 4; k++)
            dfs(r + dr[k], c + dc[k]);
    }

public:

    // 1.Count Islands
    int countIslands() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        string line;
        vector<vector<int>> tempGrid;

        // Read grid until empty line
        while (true) {
            getline(cin, line);
            if (line.empty()) break;

            stringstream ss(line);
            vector<int> row;
            int val;
            while (ss >> val)
                row.push_back(val);

            if (!row.empty())
                tempGrid.push_back(row);
        }

        if (tempGrid.empty()) {
            cout << 0;
            return 0;
        }

        rows = tempGrid.size();
        cols = tempGrid[0].size();

        memset(grid, 0, sizeof(grid));
        memset(visited, false, sizeof(visited));

        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                grid[i][j] = tempGrid[i][j];

        int islands = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    dfs(i, j);
                    islands++;
                }
            }
        }

        cout << islands;
        return islands;
    }

    // 2.Search Word
    bool searchWord() {
        char arr[50][50];
        int rows = 0, cols = 0;

        // Read 2D array until empty line
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

        string required;
        cin >> required;

        // Horizontal
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j + required.size() <= cols; j++) {
                bool found = true;
                for (int k = 0; k < required.size(); k++) {
                    if (arr[i][j + k] != required[k]) {
                        found = false;
                        break;
                    }
                }
                if (found) {
                    cout << "YES";
                    return true;
                }
            }
        }

        // Vertical
        for (int j = 0; j < cols; j++) {
            for (int i = 0; i + required.size() <= rows; i++) {
                bool found = true;
                for (int k = 0; k < required.size(); k++) {
                    if (arr[i + k][j] != required[k]) {
                        found = false;
                        break;
                    }
                }
                if (found) {
                    cout << "YES";
                    return true;
                }
            }
        }

        cout << "NO";
        return false;
    }
};

int main() {
    SearchArrays arr;

    cout << "1 for countIslands\n";
    cout << "2 for searchWord\n";
    cout << "Enter mode: ";

    int mode;
    cin >> mode;
    cin.ignore();

    if (mode == 1)
        arr.countIslands();
    else if (mode == 2)
        arr.searchWord();

    return 0;
}
