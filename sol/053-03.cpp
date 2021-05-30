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
	if (N == 1) {
		int x = Ask(1);
		cout << "! " << x << endl;
	}
	else {
		int Answer = 0, cl = 1, cr = N, cm;
		for (int i = 1; i <= 11; i++) {
			cm = (cl + cr) / 2;
			int d0 = Ask(cm + 0);
			int d1 = Ask(cm + 1);
			Answer = max({ Answer, d0, d1 });
			if (d0 < d1) { cl = cm; }
			else { cr = cm; }
		}
		cout << "! " << Answer << endl;
	}
}

int main() {
	int T; cin >> T;
	for (int i = 1; i <= T; i++) {
		solve();
	}
	return 0;
}