#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int main() {
    IOS;
    int n; cin >> n;
    vector<int>p(n);
    vector<int>q(n);
    for(int i=0;i<n;i++) cin >> p[i];
    for(int i=0;i<n;i++) cin >> q[i];
    sort(p.begin(),p.end());
    sort(q.begin(),q.end());
    int mx = INT_MIN;
    for(int i=0;i<n;i++){
        mx = max(abs(q[i]-p[i]),mx);
    }
    cout << mx << "\n";
}
