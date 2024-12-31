#include <iostream>
using namespace std;

int grid[1050][1050];
bool visited[1050][1050];
int n, m;

void floodfill(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m) return;
    if (visited[x][y] || grid[x][y] == 1) return;
    visited[x][y] = true;
    floodfill(x - 1, y); // up
    floodfill(x + 1, y); // down
    floodfill(x, y - 1); // left
    floodfill(x, y + 1); // right
}

int main() {
    cin >> n >> m;
    for (int a = 0; a < n; a++) {
        string s;
        cin >> s;
        for (int b = 0; b < m; b++) {
            if (s[b] == '#') {
                grid[a][b] = 1;
            }
            else {
                grid[a][b] = 0;
            }
        }
    }
    int ans = 0;
    for (int a = 0; a < n; a++) {
        for (int b = 0; b < m; b++) {
            if (!visited[a][b] && grid[a][b] == 0) {
                floodfill(a, b);
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
