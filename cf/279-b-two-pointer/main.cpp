#include <iostream>
using namespace std;

int n, t;
int book[100005];

int main() {
    cin >> n >> t;
    for (int i = 0; i < n; i++) {
        cin >> book[i];
    }
    
    int ans = 0;
    long long time = 0;
    int left = 0;
    
    for (int right = 0; right < n; right++) {
        time += book[right];
        
        while (time > t && left <= right) {
            time -= book[left];
            left++;
        }
        
        if (time <= t) {
            ans = max(ans, right - left + 1);
        }
    }
    
    cout << ans << endl;
    return 0;
}
