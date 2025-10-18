#include <bits/stdc++.h>
using namespace std;

int grid[50][50];
bool visited[50][50];
int rows = 0, cols = 0;

int dr[] = {-1, 1, 0, 0}; //row directions
int dc[] = {0, 0, -1, 1}; //column directions

void dfs(int r, int c) {
    if (r < 0 || r >= rows || c < 0 || c >= cols) return; 
    if (visited[r][c] || grid[r][c] == 0) return;         

    visited[r][c] = true;

    for (int k = 0; k < 4; k++) {
        dfs(r + dr[k], c + dc[k]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    vector<vector<int>> tempGrid;

    // Read grid 
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

    cout << islands << "\n";
    return 0;
}
