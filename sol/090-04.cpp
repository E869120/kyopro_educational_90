#include <vector>
#include <iostream>
using namespace std;
const int mod = 998244353;
int main() {
	int N, K;
	cin >> N >> K;
	vector<vector<vector<int> > > dp(K + 1, vector<vector<int> >(N, vector<int>(N + 1)));
	// dp[h][l][r]: ”z—ñ‚Ì‹æŠÔ (A[l], A[l+1], ..., A[r-1]) ‚ÅA‚·‚×‚Ä A[i] >= h ‚Å‚ ‚é‚à‚Ì‚ÌŒÂ”
	for (int h = K; h >= 0; --h) {
		for (int i = 0; i < N; ++i) {
			dp[h][i][i] = 1;
		}
	}
	for (int h = K; h >= 0; --h) {
		for (int l = 0; l < N; ++l) {
			for (int r = l + 1; r <= N; ++r) {
				if (h * (r - l) > K) {
					continue;
				}
				dp[h][l][r] = dp[h][l][r - 1];
				if (h != K) {
					for (int i = l; i < r; ++i) {
						dp[h][l][r] = (dp[h][l][r] + 1LL * dp[h + 1][i][r] * dp[h][l][i != l ? i - 1 : l]) % mod;
					}
				}
			}
		}
	}
	cout << dp[0][0][N] << endl;
	return 0;
}