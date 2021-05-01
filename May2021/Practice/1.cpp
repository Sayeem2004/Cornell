#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int l, w, h, c; cin >> l >> w >> h >> c;
    int ans = l*w*h;
    if (c > ans) cout << "TOO TIGHT\n";
    else if (c == ans) cout << "COZY\n";
    else cout << "SO MUCH SPACE\n";
}
