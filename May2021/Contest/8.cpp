#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    if (n == 0) {
        cout << "NOW\n";
    } else if (n < 60) {
        cout << n << " seconds\n";
    } else if (n < 3600) {
        cout << n/60 << " minutes " << n%60 << " seconds\n";
    } else if (n < 86400) {
        cout << n/3600 << " hours " << (n%3600)/60 << " minutes " << n%60 << " seconds\n";
    } else {
        cout << n/86400 << " days " << (n%86400)/3600 << " hours " << (n%3600)/60 << " minutes " << n%60 << " seconds\n";
    }
}
