#include <iostream>
#include <algorithm>
using namespace std;

long long mod = 1000000007;
unsigned long long L, R;
unsigned long long power10[22];

void init() {
	// Calculate 10^i
	power10[0] = 1;
	for (int i = 1; i <= 19; i++) power10[i] = (10ULL * power10[i - 1]);
}

long long f(long long X) {
	if (X % 2LL == 0) {
		long long v1 = (X / 2LL) % mod;
		long long v2 = (X + 1LL) % mod;
		return v1 * v2 % mod;
	}
	else {
		long long v1 = ((X + 1LL) / 2LL) % mod;
		long long v2 = X % mod;
		return v1 * v2 % mod;
	}
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