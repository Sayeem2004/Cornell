#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int,int>> vpi;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)

#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define pi pair<int, int>
#define mp make_pair
#define F first
#define S second
int n, a, b;
vector<int> val;
vector<vector<int>> adj;
vector<ll> dp[2][2];

ll dfs(int i, int include, int parent, int pinclude) {
    if (dp[include][pinclude][i]>-1) return dp[include][pinclude][i];
    if (include==1) {
        ll ans = 0, maxdif=0;
        for (int nb : adj[i]) {
            if (nb != parent) ans += dfs(nb, 0, i, 1);
            if (nb != parent && pinclude==0) maxdif = max(maxdif, dfs(nb, 1, i, 1)-dfs(nb, 0, i, 1));
        }
        ans += val[i];
        if (pinclude==0) ans = max(ans, ans+maxdif);
        dp[include][pinclude][i]=ans;
        return ans;
    } else {
        ll ans = 0;
        for (int nb : adj[i]) {
            if (nb != parent) ans += max(dfs(nb, 1, i, 0), dfs(nb, 0, i, 0));
        }
        dp[include][pinclude][i]=ans;
        return ans;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    val.rsz(n+1, 0);
    adj.rsz(n+1);
    FOR(i, 1, n+1) {
        cin >> a >> val[i];
        adj[a].pb(i);
        adj[i].pb(a);
    }
    F0R(i, 2) F0R(j, 2) dp[i][j].rsz(n+1, -1);
    cout << dfs(0, 0, 0, 0) << '\n';
}
