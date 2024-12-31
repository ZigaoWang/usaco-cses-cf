// https://cses.fi/problemset/task/1667
// https://cses.fi/problemset/result/11605087/
// TIME LIMIT EXCEEDED
// probably try bfs next time

#include <iostream>
#include <string>
using namespace std;

int grid[1050][1050];
bool visited[1050][1050];
int n, m, startX, startY;
string shortestPath;
bool found = false;

void dfs(int x, int y, string currentPath) {
    if (x < 0 || x >= n || y < 0 || y >= m) return;
    if (visited[x][y] || grid[x][y] == 1) return;
    if (grid[x][y] == 3) {
        if (!found || currentPath.length() < shortestPath.length()) {
            shortestPath = currentPath;
        }
        found = true;
        return;
    }

    if (found && currentPath.length() >= shortestPath.length()) return;

    visited[x][y] = true;

    dfs(x - 1, y, currentPath + "U"); // up
    dfs(x + 1, y, currentPath + "D"); // down
    dfs(x, y - 1, currentPath + "L"); // left
    dfs(x, y + 1, currentPath + "R"); // right

    visited[x][y] = false; // backtrack
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            if (s[j] == '#') {
                grid[i][j] = 1;
            }
            else if (s[j] == '.') {
                grid[i][j] = 0;
            }
            else if (s[j] == 'A') {
                startX = i;
                startY = j;
                grid[i][j] = 2;
            }
            else if (s[j] == 'B') {
                grid[i][j] = 3;
            }
        }
    }

    dfs(startX, startY, "");

    if (found) {
        cout << "YES" << endl;
        cout << shortestPath.length() << endl;
        cout << shortestPath << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}