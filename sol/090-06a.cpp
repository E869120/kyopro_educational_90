#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int mod = 998244353;
const int root = 3;
int power(int a, int b) {
	int ans = 1;
	while (b != 0) {
		if (b % 2 == 1) {
			ans = 1LL * ans * a % mod;
		}
		a = 1LL * a * a % mod;
		b >>= 1;
	}
	return ans;
}
int fwdpow[32], revpow[32];
void fourier_transform(vector<int>& X, bool inv) {
	int N = X.size();
	int level = 0;
	vector<int> Y(N);
	for (int i = N >> 1; i >= 1; i >>= 1) {
		++level;
		int p = (!inv ? fwdpow[level] : revpow[level]), mul = 1;
		for (int j = 0; 2 * j < N; j += i) {
			for (int k = 0; k < i; k++) {
				int g = 1LL * mul * X[2 * j + k + i] % mod;
				Y[j + k] = (X[2 * j + k] + g) % mod;
				Y[j + k + N / 2] = (X[2 * j + k] - g + mod) % mod;
			}
			mul = 1LL * mul * p % mod;
		}
		X = Y;
	}
}
vector<int> convolution(vector<int> A, vector<int> B) {
	// ‘½€®‚ÌÏ A(x) * B(x) ‚ğŒvZ—Ê O(n log n) ‚Å‹‚ß‚é
	int L = A.size() + B.size() - 1;
	int sz = 2;
	while (sz < L) {
		sz *= 2;
	}
	A.resize(sz);
	fourier_transform(A, false);
	B.resize(sz);
	fourier_transform(B, false);
	for (int i = 0; i < sz; ++i) {
		A[i] = 1LL * A[i] * B[i] % mod;
	}
	fourier_transform(A, true);
	A.resize(L);
	int inv = power(sz, mod - 2);
	for (int i = 0; i < L; ++i) {
		A[i] = 1LL * A[i] * inv % mod;
	}
	return A;
}
vector<int> polynomial_inverse(vector<int> C, int L) {
	// (C[0] + C[1] * x + ... * C[N-1] * x^(N-1)) * P(x) == 1 (mod x^L) ‚ğ–‚½‚·AL-1 ŸˆÈ‰º‚Ì‘½€® P(x) ‚ğŒvZ—Ê O(N log N) ‚Å‹‚ß‚é
	// §–ñ: C[0] == 1 ‚Å‚È‚¯‚ê‚Î‚È‚ç‚È‚¢
	int N = C.size();
	vector<int> A = { 1, 0 };
	int level = 0;
	while ((1 << level) < L) {
		int CS = min(2 << level, N);
		vector<int> P = convolution(A, vector<int>(C.begin(), C.begin() + CS));
		vector<int> Q(2 << level);
		Q[0] = 1;
		for (int j = (1 << level); j < (2 << level); ++j) {
			Q[j] = (mod - P[j]) % mod;
		}
		A = convolution(A, Q);
		A.resize(4 << level);
		++level;
	}
	A.resize(L);
	return A;
}
int main() {
	for (int i = 0; i <= 23; ++i) {
		fwdpow[i] = power(root, (mod - 1) / (1 << i));
		revpow[i] = power(root, (mod - 1) - (mod - 1) / (1 << i));
	}
	int N, K;
	cin >> N >> K;
	vector<vector<int> > dp(K + 1);
	dp[K] = { 1, 1, 1 };
	for (int i = K - 1; i >= 0; --i) {
		int limit = (i == 0 ? N : min(K / i, N));
		vector<int> C(dp[i + 1].size());
		C[0] = 1;
		for (int j = 1; j < dp[i + 1].size(); ++j) {
			C[j] = (mod - dp[i + 1][j]) % mod;
		}
		vector<int> G = polynomial_inverse(C, limit + 2);
		dp[i] = G;
	}
	cout << dp[0][N + 1] << endl;
	return 0;
}