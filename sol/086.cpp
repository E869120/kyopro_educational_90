#include <iostream>
using namespace std;

long long mod = 1000000007;
long long N, Q;
long long X[100], Y[100], Z[100], W[100];
long long x[100], y[100], z[100], w[100];

long long bit_zentansaku() {
	long long ways = 0;
	for (int i = 0; i < (1 << N); i++) {
		long long bit[15];
		for (int j = 0; j < N; j++) bit[j + 1] = (i / (1 << j)) % 2;

		bool flag = true;
		for (int j = 1; j <= Q; j++) {
			if (((bit[x[j]] | bit[y[j]]) | bit[z[j]]) != w[j]) flag = false;
		}
		if (flag == true) ways++;
	}
	return ways;
}

int main() {
	// Step #1. Input
	cin >> N >> Q;
	for (int i = 1; i <= Q; i++) cin >> X[i] >> Y[i] >> Z[i] >> W[i];

	// Step #2. Brute Force
	long long Answer = 1;
	for (int i = 0; i < 60; i++) {
		for (int j = 1; j <= Q; j++) {
			x[j] = X[j]; y[j] = Y[j]; z[j] = Z[j];
			w[j] = (W[j] / (1LL << i)) % 2LL;
		}
		long long ret = bit_zentansaku();
		Answer *= ret;
		Answer %= mod;
	}
	cout << Answer << endl;
	return 0;
}