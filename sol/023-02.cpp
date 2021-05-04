#include <iostream>
using namespace std;

long long H, W;
long long dp[25][1 << 11];
long long mod = 1000000007;
char c[25][25];

int main() {
	// Step #1. Input
	cin >> H >> W;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) cin >> c[i][j];
	}

	// Step #2. DP
	dp[0][0] = 1;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < (1 << W); j++) {
			if (dp[i][j] == 0) continue;

			for (int k = 0; k < (1 << W); k++) {
				int bit[2][12]; bool flag = false;
				for (int l = 0; l < W; l++) bit[0][l] = (j / (1 << l)) % 2;
				for (int l = 0; l < W; l++) bit[1][l] = (k / (1 << l)) % 2;
				for (int l = 0; l < W; l++) {
					if (bit[0][l] == 1 && bit[1][l] == 1) flag = true;
					if (l < W - 1 && bit[1][l] == 1 && bit[1][l + 1] == 1) flag = true;
					if (l < W - 1 && bit[0][l] == 1 && bit[1][l + 1] == 1) flag = true;
					if (l < W - 1 && bit[1][l] == 1 && bit[0][l + 1] == 1) flag = true;
					if (bit[1][l] == 1 && c[i][l] == '#') flag = true;
				}
				if (flag == false) {
					dp[i + 1][k] += dp[i][j];
					dp[i + 1][k] %= mod;
				}
			}
		}
	}

	// Step #3. Output
	long long Answer = 0;
	for (int i = 0; i < (1 << W); i++) Answer += dp[H][i];
	cout << Answer % mod << endl;
	return 0;
}