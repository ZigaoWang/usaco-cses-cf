#include <iostream>
using namespace std;

int n, num[200050], ans;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
        if (num[i] < num[i - 1]) {
            ans += (num - num[i - 1]);
            
        }
    }

    return 0;
}
