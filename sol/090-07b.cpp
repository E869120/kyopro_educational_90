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
	long long N; int K;
	cin >> N >> K;
	vector<vector<mint> > dp(K + 1);
	dp[K] = { 1, 1, 1 };
	for (int i = K - 1; i >= 1; --i) {
		int limit = min((long long)(K / i), N);
		vector<mint> C(dp[i + 1].size());
		C[0] = 1;
		for (int j = 1; j < dp[i + 1].size(); ++j) {
			C[j] = -dp[i + 1][j];
		}
		vector<mint> G = polynomial_inverse(C, limit + 2);
		dp[i] = G;
	}
	int S = min((long long)(K), N);
	vector<long long> track = { N + S + 1 };
	while (track.back() >= S + 1) {
		track.push_back(track.back() / 2);
	}
	reverse(track.begin(), track.end());
	vector<mint> CL(S + 2);
	CL[0] = 1;
	for (int i = 1; i < S + 2; ++i) {
		CL[i] = -dp[1][i];
	}
	vector<mint> GL = polynomial_inverse(CL, S + 2);
	reverse(CL.begin(), CL.end());
	vector<mint> poly(S + 1);
	poly[track[0]] = 1;
	for (int i = 1; i < track.size(); ++i) {
		poly = convolution(poly, poly);
		if (track[i] % 2 == 1) {
			poly.insert(poly.begin(), 0);
		}
		else {
			poly.push_back(0);
		}
		vector<mint> p1(poly.begin() + (S + 1), poly.end());
		reverse(p1.begin(), p1.end());
		vector<mint> p2 = convolution(p1, GL);
		p2.resize(S + 1);
		reverse(p2.begin(), p2.end());
		vector<mint> p3 = convolution(p2, CL);
		for (int j = 0; j < 2 * S + 1; ++j) {
			poly[j] -= p3[j];
		}
		poly.resize(S + 1);
	}
	cout << poly[S].val() << endl;
	return 0;
}