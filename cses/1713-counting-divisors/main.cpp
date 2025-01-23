#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int n;
vector<int> x(1000050, 1);
vector<int> primeFactor;
int check(int num) {
    int ans = 0;
    for (int i = 1; i <= sqrt(num); i++) {
        if (num % i == 0) {
            ans += 2;
        }
        if (i * i == num) {
            ans--;
        }
    }
    return ans;
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        primeFactor.push_back(check(x[i]));
    }
    for (int i = 0; i < n; i++) {
        cout << primeFactor[i] << endl;
    }
    return 0;
}
