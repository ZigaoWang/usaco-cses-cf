#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    long long expectedSum = 1LL * n * (n + 1) / 2;
    long long actualSum = 0;
    for (int i = 0; i < n - 1; i++) {
        int num;
        cin >> num;
        actualSum += num;
    }
    cout << expectedSum - actualSum << endl;
    return 0;
}
