#include <iostream>
#include <vector>
using namespace std;

long long N, K, mod = 1000000007;
long long A[5009], cl[5009];
long long dp[5009];

int main() {
	// Step #1. Input
	cin >> N >> K;
	for (int i = 1; i <= N; i++) cin >> A[i];

	// Step #2. Maeshori
	for (int i = 1; i <= N; i++) {
		int cnt = 0;
		for (int j = i - 1; j >= 1; j--) {
			for (int k = j + 1; k <= i; k++) {
				if (A[j] > A[k]) cnt++;
				if (cnt > K) { cl[i] = j; break; }
			}
			if (cnt > K) break;
		}
	}

	// Step #3. DP
	dp[0] = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = cl[i]; j < i; j++) {
			dp[i] += dp[j];
			dp[i] %= mod;
		}
	}
	cout << dp[N] << endl;
	return 0;
}