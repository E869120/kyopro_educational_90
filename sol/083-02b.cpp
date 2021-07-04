#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int N, M, Q;
	cin >> N >> M;
	vector<vector<int> > G(N);
	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b; --a, --b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	cin >> Q;
	vector<int> x(Q), y(Q);
	for (int i = 0; i < Q; ++i) {
		cin >> x[i] >> y[i]; --x[i];
	}
	for (int i = 0; i < N; ++i) {
		sort(G[i].begin(), G[i].end());
	}
	vector<int> col(N, 1);
	int B = int(sqrt(Q));
	for (int i = 0; i < B; ++i) {
		int ql = i * Q / B, qr = (i + 1) * Q / B;
		for (int j = ql; j < qr; ++j) {
			int current_col = col[x[j]];
			for (int k = ql; k < j; ++k) {
				if (x[j] == x[k] || binary_search(G[x[k]].begin(), G[x[k]].end(), x[j])) {
					current_col = y[k];
				}
			}
			cout << current_col << endl;
		}
		for (int j = ql; j < qr; ++j) {
			bool update = true;
			for (int k = j + 1; k < qr; ++k) {
				if (x[k] == x[j]) {
					update = false;
				}
			}
			if (update) {
				col[x[j]] = y[j];
				for (int k : G[x[j]]) {
					col[k] = y[j];
				}
			}
		}
	}
	return 0;
}