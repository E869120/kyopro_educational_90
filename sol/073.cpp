#include <iostream>
#include <vector>
using namespace std;

long long N, A[1 << 18], B[1 << 18];
char C[1 << 18];

long long mod = 1000000007;
long long dp[1 << 18][3];
vector<int> G[1 << 18];

void dfs(int pos, int pre) {
	long long val1 = 1, val2 = 1;
	for (int i : G[pos]) {
		if (i == pre) continue;
		dfs(i, pos);
		if (C[pos] == 'a') {
			val1 *= (dp[i][0] + dp[i][2]);
			val2 *= (dp[i][0] + dp[i][1] + 2LL * dp[i][2]);
		}
		if (C[pos] == 'b') {
			val1 *= (dp[i][1] + dp[i][2]);
			val2 *= (dp[i][0] + dp[i][1] + 2LL * dp[i][2]);
		}
		val1 %= mod;
		val2 %= mod;
	}

	if (C[pos] == 'a') {
		dp[pos][0] = val1;
		dp[pos][2] = (val2 - val1 + mod) % mod;
	}
	if (C[pos] == 'b') {
		dp[pos][1] = val1;
		dp[pos][2] = (val2 - val1 + mod) % mod;
	}
}

int main() {
	// Step #1. Input
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> C[i];
	for (int i = 1; i <= N - 1; i++) {
		cin >> A[i] >> B[i];
		G[A[i]].push_back(B[i]);
		G[B[i]].push_back(A[i]);
	}

	// Step #2. DFS
	dfs(1, -1);
	cout << dp[1][2] << endl;
	return 0;
}