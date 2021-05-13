#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long N;
long long A[1 << 18], B[1 << 18];
long long dp[1 << 18];
vector<int> G[1 << 18];

void dfs(int pos, int pre) {
	dp[pos] = 1;
	for (int i : G[pos]) {
		if (i == pre) continue;
		dfs(i, pos);
		dp[pos] += dp[i];
	}
}

int main() {
	// Step #1. “ü—Í
	cin >> N;
	for (int i = 1; i <= N - 1; i++) {
		cin >> A[i] >> B[i];
		G[A[i]].push_back(B[i]);
		G[B[i]].push_back(A[i]);
	}

	// Step #2. [‚³—Dæ’TõiDFSj
	dfs(1, -1);

	// Step #3. “š‚¦‚ğ‹‚ß‚é
	long long Answer = 0;
	for (int i = 1; i <= N - 1; i++) {
		long long r = min(dp[A[i]], dp[B[i]]);
		Answer += r * (N - r);
	}
	cout << Answer << endl;
	return 0;
}