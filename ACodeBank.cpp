#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

}

// Basic Functions
struct basefunc {
    // Change Base
    string cbase(ll n, ll b) {
        string s = "";
        vector<char> c = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J'};
        while (n > 0) {
            s = c[n%b]+s;
            n = n/b;
        }
        return s;
    }

    // Sum of Digits
    ll digsum(string s) {
        ll ans = 0;
        for (auto x : s)
            ans += x-'0';
        return ans;
    }

    // Highest Power Of 2 That Divides N
    ll div2(ll n) {
        return (n & (~(n-1)));
    }

    ll gcd(ll a, ll b) {
        if (a == 0) return b;
        return gcd(b%a, a);
    }

    // Binary Exponentiation
    ll modpow(ll x, ll n, ll m) {
        if (n == 0) return 1 % m;
        ll u = modpow(x, n/2, m);
        u = (u * u) % m;
        if (n % 2 == 1) u = (u * x) % m;
        return u;
    }

    // Permutations of a String
    vector<string> perm1(string a) {
        vector<string> s;
        sort(a.begin(),a.end());
        s.pb(a);
        while (next_permutation(a.begin(),a.end()))
            s.pb(a);
        return s;
    }

    // Prime Factorization of an lleger
    vector<ll> pfactor(ll n) {
        vector<ll> f;
        while (n % 2 == 0) {
            f.pb(2);
            n /= 2;
        }
        for (ll x = 3; x*x <= n; x += 2) {
            while (n%x == 0) {
                f.pb(x);
                n /= x;
            }
        }
        if (n > 1) f.pb(n);
        return f;
    }

    // Prime or Composite
    bool prime(ll n) {
        if (n < 2) return false;
        if (n == 2 || n == 3 || n == 5 || n == 7) return true;
        if (n % 2 == 0) return false;
        for (ll x = 3; x*x <= n; x += 2) {
            if (n % x == 0) return false;
        }
        return true;
        }

    // Sieve of Eratosthenes
    vector<ll> sieve(ll a, ll b) {
        vector<ll> v(b+1);
        for (ll x = 2; x <= b; x++) {
            if (v[x]) continue;
            for (ll u = 2 * x; u <= b; u += x) v[u] = x;
        }
        vector<ll> ans = {v.begin()+a, v.end()};
        return ans;
    }
}

// Segment Tree
struct segtree {
    #include <bits/stdc++.h>
    using namespace std;
    #define ll int64_t

    int n;  // array size
    int st[400000];

    void build() {  // build the tree
        for (int i = n - 1; i > 0; --i)
            st[i] = st[i<<1] + st[i<<1|1];
    }

    void update(int p, int value) {  // update at position p
        for (st[p += n] = value; p > 1; p >>= 1)
            st[p>>1] = st[p] + st[p^1];
    }

    void updaterange(int l, int r, int value) { // update on interval [l,r)
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l&1) st[l++] += value;
            if (r&1) st[--r] += value;
        }
    }

    int get(int p) { // get at position p
        return st[p+n];
    }

    int getrange(int l, int r) {  // get on interval [l, r)
        int res = 0;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l&1) res += st[l++];
            if (r&1) res += t[--r];
        }
        return res;
    }

    int main() {
        ios::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);

    }
}

// Ordered Set
struct ordset {
    #include <bits/stdc++.h>
    using namespace std;
    #define ll int64_t

    #include <ext/pb_ds/assoc_container.hpp>
    #include <ext/pb_ds/tree_policy.hpp>
    using namespace __gnu_pbds;
    #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

    // Set.find_by_order(index)
    // Set.find_by_key(number)

    int main() {
        ios::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);

    }
}
