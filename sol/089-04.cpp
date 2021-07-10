#include <iostream>
#include <vector>
using namespace std;

long long N, K, mod = 1000000007;
long long A[10009], cl[10009];
long long dp[10009];

int main() {
	// Step #1. Input
	cin >> N >> K;
	for (int i = 1; i <= N; i++) cin >> A[i];

	// Step #2. Maeshori
	long long l = N, cnt = 0;
	for (int r = N; r >= 1; r--) {
		while (l >= 1 && cnt <= K) {
			l--;
			for (int i = l + 1; i <= r; i++) { if (A[l] > A[i]) cnt++; }
		}
		cl[r] = l;
		for (int i = l; i <= r - 1; i++) { if (A[i] > A[r]) cnt--; }
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