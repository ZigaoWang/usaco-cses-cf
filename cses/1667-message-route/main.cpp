#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m, a, b;
queue<int> q;
vector<int> adjList[100050];
vector<int> dist(100050, 1e9);
int route[100050];

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    dist[1] = 0;
    q.push(1);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adjList[u]) {
            if (dist[v] == 1e9) {
                dist[v] = dist[u] + 1;
                route[v] = u;
                q.push(v);
            }
        }
    }
    if (dist[n] != 1e9) {
        cout << (dist[n] + 1) << endl;
        vector<int> path;
        for (int i = n; i != 0; i = route[i]) {
            path.push_back(i);
        }
        for (int i = path.size() - 1; i >= 0; i--) {
            cout << path[i] << " ";
        }
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}
