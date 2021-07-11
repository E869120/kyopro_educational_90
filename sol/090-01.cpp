#include <vector>
#include <iostream>
using namespace std;
const int mod = 998244353;
int main() {
	int N, K;
	cin >> N >> K;
	vector<vector<int> > dp(N + 1, vector<int>(2));
	// dp[pos][flag]: A[pos-1] ‚Ü‚ÅŒˆ‚ß‚½‚Æ‚«‚ÌA’¼‘O‚Ì’l A[pos-1] ‚ª flag (0 ‚Ü‚½‚Í 1) ‚Å‚ ‚éó‘Ô‚Ì”
	dp[0][0] = 1;
	for (int i = 1; i <= N; ++i) {
		dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
		dp[i][1] = dp[i - 1][0];
	}
	int answer = (dp[N][0] + dp[N][1]) % mod;
	cout << answer << endl;
	return 0;
}