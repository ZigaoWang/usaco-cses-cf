#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long n;
    cin >> n;

    vector<long long> sequence;
    sequence.push_back(n);

    while (n != 1) {
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = 3 * n + 1;
        }
        sequence.push_back(n);
    }

    for (size_t i = 0; i < sequence.size() - 1; i++) {
        cout << sequence[i] << " ";
    }
    cout << "1";

    return 0;
}