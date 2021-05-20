#include <vector>
#include <iostream>
using namespace std;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N, K;
	cin >> N >> K;
	vector<int> X(N), Y(N);
	for (int i = 0; i < N; ++i) {
		cin >> X[i] >> Y[i];
	}
	vector<vector<long long> > d(N, vector<long long>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			d[i][j] = (long long)(X[i] - X[j]) * (X[i] - X[j]) + (long long)(Y[i] - Y[j]) * (Y[i] - Y[j]);
		}
	}
	vector<long long> cost(1 << N);
	for (int i = 1; i < 1 << N; ++i) {
		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < j; ++k) {
				if (((i >> j) & 1) == 1 && ((i >> k) & 1) == 1) {
					cost[i] = max(cost[i], d[j][k]);
				}
			}
		}
	}
	vector<vector<long long> > dp(K + 1, vector<long long>(1 << N, 1LL << 62));
	dp[0][0] = 0;
	for (int i = 1; i <= K; ++i) {
		for (int j = 1; j < 1 << N; ++j) {
			for (int k = j; k != 0; k = (k - 1) & j) {
				dp[i][j] = min(dp[i][j], max(dp[i - 1][j - k], cost[k]));
			}
		}
	}
	cout << dp[K][(1 << N) - 1] << endl;
	return 0;
}