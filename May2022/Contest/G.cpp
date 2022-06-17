#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	int cnt0 = 0, cnt1 = 0;
	int curr; cin >> curr;
	for (int i = 0; i < 8; i++) {
		int val; cin >> val;
		cnt0 += (0 == val);
		cnt1 += (1 == val);
	}
	if (curr == 1) {
		if (cnt1 == 2 || cnt1 == 3) {
			cout << "1\n";
		} else {
			cout << "0\n";
		}
	} else {
		if (cnt1 == 3) {
			cout << "1\n";
		} else {
			cout << "0\n";
		}
	}
}
