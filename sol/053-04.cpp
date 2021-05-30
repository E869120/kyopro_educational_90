#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

// Ç±ÇÍ 16 âÒÇ©ÇÁå∏ÇÁÇ∑ÇÃåµÇµÇ≠Ç»Ç¢Ç©Å@ê‚ëŒ Diff 2800 Ç†ÇÈÇæÇÎÇ±ÇÒÇ»ÇÃ
int N;
int idx[1609];
int fib[16] = { 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597 };

int Ask(int pos) {
	if (idx[pos] == -1) {
		cout << "? " << pos << endl;
		int t; cin >> t;
		idx[pos] = t;
		return t;
	}
	return idx[pos];
}

void solve() {
	cin >> N;

	int Answer = 0;
	for (int i = 0; i <= N; i++) idx[i] = -1;
	for (int i = N + 1; i <= 1600; i++) idx[i] = -i;

	if (N <= 5) {
		for (int i = 1; i <= N; i++) Answer = max(Answer, Ask(i));
	}
	else {
		int cl = 0, cr = 1597, dl = 610, dr = 987;
		int el = Ask(dl);
		int er = Ask(dr);
		Answer = max({ Answer, el, er });
		if (el < er) { cl = dl; dl = dr; dr = -1; el = er; er = -1; }
		else { cr = dr; dr = dl; dl = -1; er = el; el = -1; }

		for (int i = 12; i >= 0; i--) {
			if (dl == -1) {
				dl = cl + fib[i];
				el = Ask(dl);
			}
			else if (dr == -1) {
				dr = cr - fib[i];
				er = Ask(dr);
			}
			Answer = max({ Answer, el, er });
			if (el < er) { cl = dl; dl = dr; dr = -1; el = er; er = -1; }
			else { cr = dr; dr = dl; dl = -1; er = el; el = -1; }
		}
		for (int i = cl + 1; i <= cr - 1; i++) Answer = max(Answer, Ask(i));
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