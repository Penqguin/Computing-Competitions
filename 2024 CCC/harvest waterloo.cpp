#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int dfs(vector<vector<char>>& patch, vector<vector<bool>>& visited, int x, int y);

int main() {
    int R, C;
    cin >> R;
    cin >> C;

    vector<vector<char>> patch(R, vector<char>(C));

    for (int i = 0; i < R; i++) {
        string row;
        cin >> row;

        for (int j = 0; j < C; j++) {
            patch[i][j] = row[j];
        }
    }

    int A, B;
    cin >> A;
    cin >> B;

    vector<vector<bool>> visited(R, vector<bool>(C, false));

    int total = dfs(patch, visited, A, B);

    cout << total;

    return 0;
}

int dfs(vector<vector<char>>& patch, vector<vector<bool>>& visited, int x, int y) {
    if (x < 0 || x >= patch.size() || y < 0 || y >= patch[0].size() || visited[x][y] || patch[x][y] == '*') {
        return 0;
    }

    visited[x][y] = true;

    int value = 0;
    if (patch[x][y] == 'S') {
        value = 1;
    } else if (patch[x][y] == 'M') {
        value = 5;
    } else if (patch[x][y] == 'L') {
        value = 10;
    }

    for (int i = 0; i < 4; i++) {
        value += dfs(patch, visited, x + dx[i], y + dy[i]);
    }

    return value;
}