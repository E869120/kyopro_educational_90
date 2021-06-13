#include <atcoder/all>
#include <iostream>
#include <vector>
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

	// Step #1. ì¸óÕ
	cin >> R >> G >> B >> K;
	cin >> X >> Y >> Z;

	// Step #2. ëOèàóù
	long long R_left = K - Y, R_right = R;
	long long G_left = K - Z, G_right = G;
	long long B_left = K - X, B_right = B;
	for (int i = 0; i <= R; i++) ar[i] = ncr(R, i);
	for (int i = 0; i <= G; i++) ag[i] = ncr(G, i);
	for (int i = 0; i <= B; i++) ab[i] = ncr(B, i);

	// Step #3. FFT
	vector<long long> p1(R + 1, 0), p2(G + 1, 0), p3;
	for (int i = R_left; i <= R_right; i++) p1[i] = ar[i];
	for (int i = G_left; i <= G_right; i++) p2[i] = ag[i];
	p3 = atcoder::convolution(p1, p2);

	// Step #4. ìöÇ¶ÇãÅÇﬂÇÈ
	long long Answer = 0;
	for (int i = B_left; i <= B_right; i++) {
		long long ret1 = 0, ret2 = ab[i];
		if (0 <= K - i && K - i <= (int)p3.size()) ret1 = p3[K - i];
		Answer += ret1 * ret2;
		Answer %= mod;
	}
	cout << Answer << endl;
	return 0;
}