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
int n, w, l, h, q, x1, x2, Y1, y2, z1, z2;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> w >> l >> h;
    ll p[3][w+1][l+1][h+1];
    F0R(i, w+1) F0R(j, l+1) F0R(k, h+1) p[0][i][j][k]=p[1][i][j][k]=p[2][i][j][k]=0;
    FOR(i, 1, w+1) FOR(j, 1, l+1) FOR(k, 1, h+1) cin >> p[0][i][j][k] >> p[1][i][j][k] >> p[2][i][j][k];
    FOR(i, 1, w+1) F0R(j, l+1) F0R(k, h+1) F0R(t, 3) p[t][i][j][k] += p[t][i-1][j][k];
    FOR(i, 0, w+1) FOR(j, 1, l+1) FOR(k, 0, h+1) F0R(t, 3) p[t][i][j][k] += p[t][i][j-1][k];
    FOR(i, 0, w+1) FOR(j, 0, l+1) FOR(k, 1, h+1) F0R(t, 3) p[t][i][j][k] += p[t][i][j][k-1];
    cin >> q;
    F0R(query, q) {
        cin >> x1 >> Y1 >> z1 >> x2 >> y2 >> z2;
        F0R(t, 3) {
            ll psum = p[t][x2][y2][z2]
            - p[t][x1-1][y2][z2] - p[t][x2][Y1-1][z2] - p[t][x2][y2][z1-1]
            + p[t][x1-1][Y1-1][z2] + p[t][x1-1][y2][z1-1] + p[t][x2][Y1-1][z1-1]
            - p[t][x1-1][Y1-1][z1-1];
            psum /= (x2-x1+1) * (y2-Y1+1) * (z2-z1+1);
            cout << psum << ' ';
        }
        cout << '\n';
    }
    return 0;
}
