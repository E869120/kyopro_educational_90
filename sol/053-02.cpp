#include <iostream>
#include <algorithm>
using namespace std;

int Ask(int pos) {
	cout << "? " << pos << endl;
	int t; cin >> t;
	return t;
}

void solve() {
	int N; cin >> N;
	int Answer = 0, cl = 1, cr = N + 1;
	for (int i = 1; i <= 20; i++) {
		int c1 = (cl + cl + cr) / 3, d1 = Ask(c1);
		int c2 = (cl + cr + cr) / 3, d2 = Ask(c2);
		Answer = max({ Answer, d1, d2 });
		if (d1 < d2) { cl = c1; }
		else { cr = c2; }
	}
	cout << "! " << Answer << endl;
}

int main() {
	int T; cin >> T;
	for (int i = 1; i <= T; i++) {
		solve();
	}
	return 0;
}