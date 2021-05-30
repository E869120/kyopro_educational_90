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
	int Answer = 0;
	for (int i = 1; i <= N; i++) {
		Answer = max(Answer, Ask(i));
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