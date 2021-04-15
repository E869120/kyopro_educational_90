#include <iostream>
using namespace std;

long long modpow(long long a, long long b, long long m) {
	// a^b mod m を求める
	long long p = 1, q = a;
	for (int i = 0; i < 30; i++) {
		if ((b & (1LL << i)) != 0) {
			p *= q; p %= m;
		}
		q *= q; q %= m;
	}
	return p;
}

long long Div(long long a, long long b, long long m) {
	// a÷b の mod m での逆元を求める
	return (a * modpow(b, m - 2, m)) % m;
}

// 変数
long long mod = 1000000007;
long long N;
long long fact[200009];
long long factinv[200009];

void init() {
	fact[0] = 1;
	for (int i = 1; i <= 200000; i++) fact[i] = (1LL * i * fact[i - 1]) % mod;
	for (int i = 0; i <= 200000; i++) factinv[i] = Div(1, fact[i], mod);
}

long long ncr(int n, int r) {
	if (n < r || r < 0) return 0;
	return (fact[n] * factinv[r] % mod) * factinv[n - r] % mod;
}

long long query(int K) {
	long long ret = 0;
	// 「N 個中何個選ぶか」を全探索
	// そもそも K が大きいと 1 個か 2 個しか選べないので、そこに着目する
	for (int i = 1; i <= N / K + 1; i++) {
		int s1 = N - (K - 1) * (i - 1);
		int s2 = i;
		ret += ncr(s1, s2);
		ret %= mod;
	}
	return ret;
}

int main() {
	// Step #1. 入力
	cin >> N;

	// Step #2. nCr を求めるために必要な値をメモ（fact / factinv など）
	init();

	// Step #3. 出力
	for (int k = 1; k <= N; k++) {
		long long Answer = query(k);
		cout << Answer << endl;
	}
	return 0;
}