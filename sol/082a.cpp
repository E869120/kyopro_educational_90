#include <iostream>
#include <algorithm>
using namespace std;

long long mod = 1000000007;
unsigned long long L, R;
unsigned long long power10[22];

long long modpow(long long a, long long b, long long m) {
	long long p = 1, q = a;
	for (int i = 0; i < 30; i++) {
		if ((b & (1LL << i)) != 0) { p *= q; p %= m; }
		q *= q; q %= m;
	}
	return p;
}

long long Div(long long a, long long b, long long m) {
	// Get the value of a/b
	return (a * modpow(b, m - 2, m)) % m;
}

void init() {
	// Calculate 10^i
	power10[0] = 1;
	for (int i = 1; i <= 19; i++) power10[i] = (10ULL * power10[i - 1]);
}

long long f(long long X) {
	// Calculate 1 + 2 + ... + X mod 1000000007
	long long v1 = X % mod;
	long long v2 = (X + 1) % mod;
	long long v = v1 * v2 % mod;
	return Div(v, 2, mod);
}

int main() {
	// Step #1. Initialize / Input
	init();
	cin >> L >> R;

	// Step #2. Brute Force by Digit-Size
	long long Answer = 0;
	for (int i = 1; i <= 19; i++) {
		unsigned long long vl = max(L, power10[i - 1]);
		unsigned long long vr = min(R, power10[i] - 1ULL);
		if (vl > vr) continue;
		long long val = (f(vr) - f(vl - 1) + mod) % mod;
		Answer += 1LL * i * val;
		Answer %= mod;
	}

	// Step #3. Output The Answer
	cout << Answer << endl;
	return 0;
}