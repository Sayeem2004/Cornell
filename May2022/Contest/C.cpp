#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll n, m, t; cin >> n >> m >> t;
    vector<vector<ll>> V(m, vector<ll>(n));
    for (int i = 0; i < m; i++) {
        for (int q = 0; q < n; q++) {
            cin >> V[i][q];
        }
    }
    vector<vector<ll>> DP(m+1, vector<ll>((1 << n)+1, 1000000000000));
    for (int i = 0; i <= m; i++) DP[i][0] = 0;
    for (int q = 0; q <= (1 << n); q++) DP[0][q] = 0;
    for (int i = 1; i <= m; i++) {
        for (int q = 1; q <= (1 << n); q++) {
            for (int r = 0; r < n; r++) {
                if (q & (1 << r)) {
                    int prev = q - (1 << r);
                    DP[i][q] = min(DP[i][q], DP[i][prev] + V[i-1][r]); 
                }
            }
        }
    }
    for (int i = 0; i <= m; i++) {
        for (int q = 0; q <= (1 << n); q++) {
            cout << DP[i][q] << " ";
        }
        cout << "\n";
    }
    cout << DP[m][(1 << n)] << "\n";
}
