// https://cses.fi/problemset/task/1674

#include <iostream>
#include <vector>
using namespace std;

vector<int> adjList[200500];
int ans[200500];
int tree(int node, int parent) {
    int sub = 0;
    for (int na : adjList[node]) {
        if (na == parent) continue;
        sub += tree(na, node);
    }
    ans[node] = sub;
    return sub + 1;
}
int main() {
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int a;
        cin >> a;
        adjList[a].push_back(i);
    }
    tree(1, 0);
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}
