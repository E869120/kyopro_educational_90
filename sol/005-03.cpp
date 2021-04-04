#include <iostream>
using namespace std;

long long modpow(long long a, long long b, long long m) {
	long long p = 1, q = a;
	for (int i = 0; i < 63; i++) {
		if ((b & (1LL << i)) != 0) {
			p *= q;
			p %= m;
		}
		q *= q;
		q %= m;
	}
	return p;
}

const long long mod = 1000000007;

// 入力
long long N, B, K;
long long C[11];

// その他の変数
long long power10[64];
long long DP[64][1009];
long long Answer[64][1009];

int main() {
	// Step #1. 入力
	cin >> N >> B >> K;
	for (int i = 1; i <= K; i++) cin >> C[i];
	
	// Step #2. 前計算
	for (int i = 0; i <= 62; i++) {
		power10[i] = modpow(10LL, (1LL << i), B);
	}
	
	// Step #3. dp[1][i] を求める
	for (int i = 1; i <= K; i++) {
		DP[0][C[i] % B] += 1;
	}

	// Step #4. dp[1][i], dp[2][i], ..., dp[2^n][i] を求める
	for (int i = 0; i < 62; i++) {
		for (int j = 0; j < B; j++) {
			for (int k = 0; k < B; k++) {
				int nex = (j * power10[i] + k) % B;
				DP[i + 1][nex] += DP[i][j] * DP[i][k];
				DP[i + 1][nex] %= mod;
			}
		}
	}

	// Step #5. 繰り返し二乗法により dp[N][i] を求める
	Answer[0][0] = 1;
	for (int i = 0; i < 62; i++) {
		if ((N & (1LL << i)) != 0LL) {
			for (int j = 0; j < B; j++) {
				for (int k = 0; k < B; k++) {
					int nex = (j * power10[i] + k) % B;
					Answer[i + 1][nex] += Answer[i][j] * DP[i][k];
					Answer[i + 1][nex] %= mod;
				}
			}
		}
		else {
			for (int j = 0; j < B; j++) Answer[i + 1][j] = Answer[i][j];
		}
	}

	// Step #6. 出力
	cout << Answer[62][0] << endl;
	return 0;
}