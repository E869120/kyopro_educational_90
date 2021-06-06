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
	vector<int> A(Q), B(Q);
	for (int i = 0; i < Q; ++i) {
		cin >> A[i] >> B[i];
		--A[i], --B[i];
	}
	for (int i = 0; i * 64 < Q; ++i) {
		vector<unsigned long long> dp(N, 0);
		for (int j = i * 64; j < (i + 1) * 64 && j < Q; ++j) {
			dp[A[j]] |= 1ULL << (j - i * 64);
		}
		for (int j = 0; j < M; ++j) {
			dp[Y[j]] |= dp[X[j]];
		}
		for (int j = i * 64; j < (i + 1) * 64 && j < Q; ++j) {
			cout << (((dp[B[j]] >> (j - i * 64)) & 1) == 1 ? "Yes\n" : "No\n");
		}
	}
	return 0;
}