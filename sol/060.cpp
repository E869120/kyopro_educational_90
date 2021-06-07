#include <iostream>
#include <algorithm>
using namespace std;

int N, A[1 << 19];
int P[1 << 19], Q[1 << 19];
int dp[1 << 19], cnt = 0;

int main() {
	// Step #1. “ü—Í
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];

	// Step #2. ¶‘¤‚Ì LIS ‚ğ‹‚ß‚é
	for (int i = 1; i <= N; i++) {
		int pos1 = lower_bound(dp, dp + cnt, A[i]) - dp;
		dp[pos1] = A[i];
		P[i] = pos1 + 1;
		if (pos1 == cnt) cnt++;
	}

	// Step #3. ‰E‘¤‚Ì LIS ‚ğ‹‚ß‚é
	cnt = 0;
	for (int i = N; i >= 1; i--) {
		int pos1 = lower_bound(dp, dp + cnt, A[i]) - dp;
		dp[pos1] = A[i];
		Q[i] = pos1 + 1;
		if (pos1 == cnt) cnt++;
	}

	// Step #4. “š‚¦‚ğ‹‚ß‚é
	int Answer = 0;
	for (int i = 1; i <= N; i++) {
		Answer = max(Answer, P[i] + Q[i] - 1);
	}
	cout << Answer << endl;
	return 0;
}