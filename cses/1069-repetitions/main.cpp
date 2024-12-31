#include <iostream>
using namespace std;
string s;
int ans, temp;
int main() {
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == s[i - 1]) {
            temp++;
            ans = max(ans, temp);
        }
        else if (s[i] != s[i - 1]) {
            temp = 0;
        }

    }
    cout << (ans + 1) << endl;
    return 0;
}
