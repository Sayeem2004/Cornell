#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)

#define pb push_back
#define rsz resize
int n, m, a, b, c, tim=0, ldep, q, u, v, w;
vi st, ed, arr;
vector<vi> adj, up;

void dfs(int i, int parent) {
    up[i][0]=parent;
    st[i]=tim;
    arr[tim]=i;
    tim++;
    for (int nb : adj[i]) {
        if (nb!=parent) dfs(nb, i);
    }
    ed[i]=tim-1;
}

bool anc(int i, int j) {
    return st[i]<=st[j] && ed[i]>=ed[j];
}

int lca(int i, int j) {
    if (anc(j, i)) return j;
    if (anc(i, j)) return i;
    for (int d = ldep-1; d >= 0; d--) {
        if (! anc(up[i][d], j)) i=up[i][d];
    }
    return up[i][0];
}

string eval() {
    int h = lca(u, v);
    if (anc(h, w) && anc(w, u)) return "NO";
    if (anc(h, w) && anc(w, v)) return "NO";
    return "YES";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    adj.rsz(n);
    F0R(i, n-1) {
        cin >> a >> b;
        a--; b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    st.rsz(n);
    ed.rsz(n);
    arr.rsz(n);
    while (pow(2, ldep) <= n) ldep++;
    ldep++;
    up.rsz(n, vi(ldep));
    dfs(0, 0);
    for (int i = 1; i < up[0].size(); i++) {
        for (int j = 0; j < n; j++) {
            up[j][i] = up[up[j][i-1]][i-1];
        }
    }
    cin >> q;
    F0R(query, q) {
        cin >> u >> v >> w;
        u--; v--; w--;
        cout << eval() << '\n';
    }
}
