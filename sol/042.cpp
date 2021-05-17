#include <vector>
#include <iostream>
using namespace std;
const int mod = 1000000007;
int main() {
	int K;
	cin >> K;
	if (K % 9 == 0) {
		vector<int> dp(K + 1);
		dp[0] = 1;
		for (int i = 1; i <= K; ++i) {
			for (int j = i - 1; j >= i - 9 && j >= 0; --j) {
				dp[i] += dp[j];
				if (dp[i] >= mod) dp[i] -= mod;
			}
		}
		cout << dp[K] << endl;
	}
	else {
		cout << 0 << endl;
	}
	return 0;
}