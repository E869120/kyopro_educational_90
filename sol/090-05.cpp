#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int mod = 998244353;
int main() {
	int N, K;
	cin >> N >> K;
	vector<vector<int> > dp(K + 1);
	// dp[h][m]: ’·‚³ m ‚ÌðŒ‚ð–ž‚½‚·”—ñ‚ÅA‚·‚×‚Ä A[i] >= h ‚ð–ž‚½‚·‚æ‚¤‚È‚à‚Ì‚ÌŒÂ”
	dp[K] = { 0, 1 };
	for (int i = K - 1; i >= 0; --i) {
		int limit = (i == 0 ? N : min(K / i, N));
		dp[i].resize(limit + 1);
		for (int j = 1; j <= limit; ++j) {
			dp[i][j] = (j != 1 ? dp[i][j - 1] : 1);
			for (int k = 2; k <= j + 1 && k <= dp[i + 1].size(); ++k) {
				dp[i][j] = (dp[i][j] + 1LL * dp[i + 1][k - 1] * (k < j ? dp[i][j - k] : 1)) % mod;
			}
		}
	}
	cout << dp[0][N] << endl;
	return 0;
}