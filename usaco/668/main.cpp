#include <iostream>
#include <vector>
#include <cmath>
//#include <stdio.h>
using namespace std;

double distance(int x1, int x2, int y1, int y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

vector<int> adjList[205];
vector<int> visited;
void dfs(int node) {
    visited[node] = 1;
    for (int neighbor : adjList[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}

int n, power;
vector<pair<pair<int, int>, int>> pointers;

int main() {
//    freopen("moocast.in", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y >> power;
        pointers.push_back({{x, y}, power});
    }
    for (int j = 0; j < pointers.size(); j++) {
        for (int k = 0; k < pointers.size(); k++) {
            if (j != k) {
                int x1 = pointers[j].first.first;
                int y1 = pointers[j].first.second;
                int x2 = pointers[k].first.first;
                int y2 = pointers[k].first.second;
                if (distance(x1, x2, y1, y2) <= pointers[j].second) {
                    adjList[j].push_back(k);
                }
            }
        }
    }
    int ans = 0, temp = 0;
    for (int i = 0; i < n; i++) {
        temp = 0;
        visited.assign(n, 0);
        dfs(i);
        for (int j = 0; j < n; j++) {
            temp += visited[j];
        }
        ans = max(ans, temp);
    }
//    freopen("moocast.out", "w", stdout);
    cout << ans << endl;
    return 0;
}
