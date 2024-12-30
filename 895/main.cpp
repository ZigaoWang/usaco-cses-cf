#include <iostream>
//#include <stdio.h>
using namespace std;

int grid[1050][1050];
bool visited[1050][1050];
int n;

int ans, temp1, temp2, area, perimeter;
void floodfill(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= n) return;
    if (visited[x][y] || grid[x][y] == 0) return;
    visited[x][y] = true;
    temp1++;
    if (x == 0 || grid[x - 1][y] == 0) {
        temp2++;
    }
    if (y == 0 || grid[x][y - 1] == 0) {
        temp2++;
    }
    if (x == n - 1 || grid[x + 1][y] == 0) {
        temp2++;
    }
    if (y == n - 1 || grid[x][y + 1] == 0) {
        temp2++;
    }
    floodfill(x - 1, y); // up
    floodfill(x + 1, y); // down
    floodfill(x, y - 1); // left
    floodfill(x, y + 1); // right
}

int main() {
//    freopen("perimeter.in", "r", stdin);
    cin >> n;
    for (int a = 0; a < n; a++) {
        string s;
        cin >> s;
        for (int b = 0; b < n; b++) {
            if (s[b] == '#') {
                grid[a][b] = 1;
            }
            else {
                grid[a][b] = 0;
            }
        }
    }
    for (int a = 0; a < n; a++) {
        for (int b = 0; b < n; b++) {
            if (!visited[a][b] && grid[a][b] == 1) {
                temp1 = 0;
                temp2 = 0;
                floodfill(a, b);
                if (temp1 == area) {
                    perimeter = min(perimeter, temp2);
                }
                else {
                    area = max(temp1, area);
                    perimeter = max(temp2, perimeter);
                }
            }
        }
    }
//    freopen("perimeter.out", "w", stdout);
    cout << area << " " << perimeter << endl;
    return 0;
}