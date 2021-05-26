#include <iostream>
using namespace std;

int mod = 1000000007;
int N, L, dp[100009];

int main() {
	// Step #1. 入力
	cin >> N >> L;

	// Step #2. 動的計画法
	dp[0] = 1;
	for (int i = 1; i <= N; i++) {
		if (i < L) dp[i] = dp[i - 1];
		else dp[i] = (dp[i - 1] + dp[i - L]) % mod;
	}

	// Step #3. 出力
	cout << dp[N] << endl;
	return 0;
}