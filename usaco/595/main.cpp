#include <iostream>
//#include <stdio.h>
using namespace std;

int n;
int first[7];
int last[7];

int main() {
//    freopen("div7.in", "r", stdin);
    cin >> n;
    int cow = 0;
    for (int j = 1; j <= n; j++) {
        int temp = 0;
        cin >> temp;
        cow = (cow + temp) % 7;
        // first and last index
        if (first[cow] == 0) {
            first[cow] = j;
        }
        else {
            last[cow] = j;
        }
    }
    int ans = 0;
    for (int i = 0; i < 7; i++) {
        ans = max(ans, last[i] - first [i]);
    }
//    freopen("div7.out", "w", stdout);
    cout << ans << endl;
    return 0;
}
