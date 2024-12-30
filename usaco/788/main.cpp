#include <iostream>
#include <vector>
//#include <stdio.h>
using namespace std;

vector<pair<pair<int, int>, int>> adjList[5005];
vector<bool> visited(5005, false);
int n, q, temp;
void dfs(int node, int k) {
    visited[node] = true;
    for (auto neighbor : adjList[node]) {
        if (!visited[neighbor.first.second] && neighbor.second >= k) {
            dfs(neighbor.first.second, k);
            temp++;
        }
    }
}
int main() {
//    freopen("mootube.in", "r", stdin);
    cin >> n >> q;
    for (int i = 0; i < n - 1; i++) {
        int a, b, k;
        cin >> a >> b >> k;
        adjList[a].push_back({{a, b}, k});
        adjList[b].push_back({{b, a}, k});
    }
//    freopen("mootube.out", "w", stdout);
    while (q--) {
        int k, v;
        cin >> k >> v;
        temp = 0;
        fill(visited.begin(), visited.end(), false);
        dfs(v, k);
        cout << temp << endl;
    }
    return 0;
}
