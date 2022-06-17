#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int N = 100005;
vector<vector<int>> A(N);
vector<int> T(N, -1);
int val = 0, ans = 0;

void dfs(int n, int mn) {
    T[n] = val++;
    for (int u : A[n]) {
        if (T[u] >= mn) {
            ans += T[n]-T[u]+1;
            return;
        } else if (T[u] == -1) {
            dfs(u, mn);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        A[i].push_back(a-1);
    }
    for (int i = 0; i < n; i++) {
        if (T[i] == -1) dfs(i, val);
    }
    cout << ans << "\n";
}
