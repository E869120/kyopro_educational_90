#include <vector>
#include <iostream>
#include <algorithm>
#include <atcoder/all>
using namespace std;
using mint = atcoder::modint998244353;
vector<mint> polynomial_inverse(vector<mint> C, int L) {
	// (C[0] + C[1] * x + ... * C[N-1] * x^(N-1)) * P(x) == 1 (mod x^L) ‚ğ–‚½‚·AL-1 ŸˆÈ‰º‚Ì‘½€® P(x) ‚ğŒvZ—Ê O(N log N) ‚Å‹‚ß‚é
	// §–ñ: C[0] == 1 ‚Å‚È‚¯‚ê‚Î‚È‚ç‚È‚¢
	int N = C.size();
	vector<mint> A = { 1, 0 };
	int level = 0;
	while ((1 << level) < L) {
		int CS = min(2 << level, N);
		vector<mint> P = atcoder::convolution(A, vector<mint>(C.begin(), C.begin() + CS));
		vector<mint> Q(2 << level);
		Q[0] = 1;
		for (int j = (1 << level); j < (2 << level); ++j) {
			Q[j] = -P[j];
		}
		A = atcoder::convolution(A, Q);
		A.resize(4 << level);
		++level;
	}
	A.resize(L);
	return A;
}
int main() {
	int N, K;
	cin >> N >> K;
	vector<vector<mint> > dp(K + 1);
	dp[K] = { 1, 1, 1 };
	for (int i = K - 1; i >= 0; --i) {
		int limit = (i == 0 ? N : min(K / i, N));
		vector<mint> C(dp[i + 1].size());
		C[0] = 1;
		for (int j = 1; j < dp[i + 1].size(); ++j) {
			C[j] = -dp[i + 1][j];
		}
		vector<mint> G = polynomial_inverse(C, limit + 2);
		dp[i] = G;
	}
	cout << dp[0][N + 1].val() << endl;
	return 0;
}