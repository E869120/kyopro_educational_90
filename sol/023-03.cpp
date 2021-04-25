#include <iostream>
using namespace std;

long long mod = 1000000007;
long long H, W;
long long dp[18][18][1 << 18];
char c[25][25];

int main() {
	// Step #1. Input
	cin >> H >> W;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) cin >> c[i][j];
	}

	// Step #2. DP
	dp[0][0][0] = 1;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			int n1 = i, n2 = j + 1;
			if (n2 == W) { n1 += 1; n2 = 0; }

			for (int k = 0; k < (1 << (W + 1)); k++) {
				if (dp[i][j][k] == 0) continue;
				int bit[25];
				for (int l = 0; l <= W; l++) bit[l] = (k / (1 << l)) % 2;
				dp[n1][n2][k >> 1] += dp[i][j][k];
				dp[n1][n2][k >> 1] %= mod;
				bool flag = true;
				if (c[i][j] == '#') flag = false;
				if (bit[0] == 1 && i >= 1 && j >= 1) flag = false;
				if (bit[1] == 1 && i >= 1) flag = false;
				if (bit[2] == 1 && i >= 1 && j <= W - 2) flag = false;
				if (bit[W] == 1 && j >= 1) flag = false;
				if (flag == true) {
					dp[n1][n2][(k >> 1) + (1 << W)] += dp[i][j][k];
					dp[n1][n2][(k >> 1) + (1 << W)] %= mod;
				}
			}
		}
	}

	// Step #3. Get Answer
	long long Answer = 0;
	for (int i = 0; i < (1 << (W + 1)); i++) Answer += dp[H][0][i];
	cout << Answer % mod << endl;
	return 0;
}