// https://cses.fi/problemset/task/1667
// https://cses.fi/problemset/result/11605087/
// TIME LIMIT EXCEEDED
// probably try bfs next time

#include <iostream>
#include <string>
#include <queue>
using namespace std;

queue<int> q;
string route[1050];
int grid[1050][1050];
int n, m, startX, startY;

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
    q.push(startX);
    q.push(startY);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        int y = q.front();
        q.pop();
        if (x > 0 && grid[x - 1][y] == 0) {
            q.push(x - 1);
            q.push(y);
            grid[x - 1][y] = 2;
            route[x - 1][y] = 'U';
        }
        if (x < n - 1 && grid[x + 1][y] == 0) {
            q.push(x + 1);
            q.push(y);
            grid[x + 1][y] = 2;
            route[x + 1][y] = 'D';
        }
        if (y > 0 && grid[x][y - 1] == 0) {
            q.push(x);
            q.push(y - 1);
            grid[x][y - 1] = 2;
            route[x][y - 1] = 'L';
        }
        if (y < m - 1 && grid[x][y + 1] == 0) {
            q.push(x);
            q.push(y + 1);
            grid[x][y + 1] = 2;
            route[x][y + 1] = 'R';
        }
    }
    if (grid[startX][startY] != 2) {
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;
        string s;
        int x = startX;
        int y = startY;
        while (grid[x][y] != 3) {
            s += route[x][y];
            if (route[x][y] == 'U') {
                x--;
            }
            else if (route[x][y] == 'D') {
                x++;
            }
            else if (route[x][y] == 'L') {
                y++;
            }
            else if (route[x][y] == 'R') {
                y--;
            }
        }
        cout << s.length() << endl;
        for (int i = s.length() - 1; i >= 0; i--) {
            cout << s[i];
        }
        cout << endl;
    }
    return 0;
}
