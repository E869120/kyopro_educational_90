#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N, M, Q;
	cin >> N >> M >> Q;
	vector<int> X(M), Y(M);
	for (int i = 0; i < M; ++i) {
		cin >> X[i] >> Y[i];
		--X[i], --Y[i];
	}
	vector<long long> g(M);
	for (int i = 0; i < M; ++i) {
		g[i] = 1LL * Y[i] * N + X[i];
	}
	sort(g.begin(), g.end());
	for (int i = 0; i < M; ++i) {
		X[i] = g[i] % N;
		Y[i] = g[i] / N;
	}
	for (int i = 0; i < Q; ++i) {
		int A, B;
		cin >> A >> B;
		--A, --B;
		vector<bool> vis(N, false);
		vis[A] = true;
		for (int j = 0; j < M; ++j) {
			if (vis[X[j]]) {
				vis[Y[j]] = true;
			}
		}
		cout << (vis[B] ? "Yes\n" : "No\n");
	}
	return 0;
}