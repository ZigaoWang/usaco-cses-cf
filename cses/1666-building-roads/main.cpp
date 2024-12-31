#include <iostream>
#include <vector>

using namespace std;

int n, m, a, b;
vector<int> adjList[100050];
int visited[100050];
void dfs(int node) {
    visited[node] = 1;
    for (int neighbor : adjList[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}
vector<pair <int, int>> ans;
int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    int last = -1;
    for (int j = 1; j <= n; j++) {
        if (!visited[j]) {
            if (last != -1) {
                ans.push_back({last, j});
            }
            dfs(j);
            last = j;
        }
    }
    cout << ans.size() << endl;
    for (auto p : ans) {
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}
