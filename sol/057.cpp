#include <vector>
#include <iostream>
using namespace std;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	vector<vector<int> > D(N, vector<int>(M, 0));
	for (int i = 0; i < N; ++i) {
		int t, x;
		cin >> t;
		for (int j = 0; j < t; ++j) {
			cin >> x;
			D[i][--x] = 1;
		}
	}
	vector<int> S(M);
	for (int i = 0; i < M; ++i) {
		cin >> S[i];
	}
	int pos = 0;
	for (int i = 0; i < M; ++i) {
		bool found = false;
		for (int j = pos; j < N; ++j) {
			if (D[j][i] == 1) {
				if (j != pos) {
					swap(D[j], D[pos]);
				}
				found = true;
				break;
			}
		}
		if (found) {
			for (int j = 0; j < N; ++j) {
				if (j != pos && D[j][i] == 1) {
					for (int k = i; k < M; ++k) {
						D[j][k] ^= D[pos][k];
					}
				}
			}
			if (S[i] == 1) {
				for (int j = i; j < M; ++j) {
					S[j] ^= D[pos][j];
				}
			}
			++pos;
		}
	}
	if (S == vector<int>(M, 0)) {
		int ans = 1;
		for (int i = pos; i < N; ++i) {
			ans = ans * 2 % 998244353;
		}
		cout << ans << endl;
	}
	else {
		cout << 0 << endl;
	}
	return 0;
}