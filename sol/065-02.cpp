#include <iostream>
using namespace std;

long long mod = 998244353;
long long fact[1 << 19], inv[1 << 19];

long long modpow(long long a, long long b, long long m) {
	long long p = 1, q = a;
	for (int i = 0; i < 32; i++) {
		if ((b & (1LL << i)) != 0LL) {
			p *= q; p %= m;
		}
		q *= q; q %= m;
	}
	return p;
}

long long Div(long long a, long long b, long long m) {
	return (a * modpow(b, m - 2, m)) % m;
}

long long ncr(long long n, long long r) {
	if (n < r || r < 0) return 0;
	return (fact[n] * inv[r] % mod) * inv[n - r] % mod;
}

void init() {
	fact[0] = 1LL;
	for (int i = 1; i <= 500000; i++) fact[i] = (1LL * i * fact[i - 1]) % mod;
	for (int i = 0; i <= 500000; i++) inv[i] = Div(1, fact[i], mod);
}

long long R, G, B, K;
long long X, Y, Z;
long long ar[1 << 19], ag[1 << 19], ab[1 << 19];

int main() {
	init();

	// Step #1. “ü—Í
	cin >> R >> G >> B >> K;
	cin >> X >> Y >> Z;

	// Step #2. ‘Oˆ—
	for (int i = 0; i <= R; i++) ar[i] = ncr(R, i);
	for (int i = 0; i <= G; i++) ag[i] = ncr(G, i);
	for (int i = 0; i <= B; i++) ab[i] = ncr(B, i);

	// Step #3. ‘S’Tõ
	long long Answer = 0;
	for (int i = 0; i <= R; i++) {
		for (int j = 0; j <= G; j++) {
			int rem = K - i - j;
			if (rem < 0 || rem > B) continue;
			if (i + j > X || j + rem > Y || rem + i > Z) continue;
			Answer += (ar[i] * ag[j] % mod) * ab[rem] % mod;
			Answer %= mod;
		}
	}
	cout << Answer << endl;
	return 0;
}