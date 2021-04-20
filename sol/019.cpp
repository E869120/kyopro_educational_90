#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int N;
int A[1 << 18];
int dp[409][409];

int main() {
	// Step #1. Input
	cin >> N;
	for (int i = 1; i <= 2 * N; i++) cin >> A[i];

	// Step #2. Initialize
	for (int i = 1; i <= 2 * N; i++) {
		for (int j = i; j <= 2 * N; j++) dp[i][j] = (1 << 29);
		if (i < 2 * N) dp[i][i + 1] = abs(A[i] - A[i + 1]);
	}

	// Step #3. DP
	for (int i = 3; i <= 2 * N; i += 2) {
		for (int j = 1; j <= 2 * N - i; j++) {
			int cl = j, cr = j + i;
			for (int k = cl; k <= cr - 1; k++) dp[cl][cr] = min(dp[cl][cr], dp[cl][k] + dp[k + 1][cr]);
			dp[cl][cr] = min(dp[cl][cr], dp[cl + 1][cr - 1] + abs(A[cl] - A[cr]));
		}
	}

	// Step #4. Output
	cout << dp[1][2 * N] << endl;
	return 0;
}