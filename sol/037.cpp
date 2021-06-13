#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class RangeMax {
public:
	int size_ = 1;
	vector<long long> dat;

	void init(int sz) {
		while (size_ <= sz) size_ *= 2;
		dat.resize(size_ * 2, -(1LL << 60));
	}
	void update(int pos, long long x) {
		pos += size_;
		dat[pos] = x;
		while (pos >= 2) {
			pos >>= 1;
			dat[pos] = max(dat[pos * 2], dat[pos * 2 + 1]);
		}
	}
	long long query_(int l, int r, int a, int b, int u) {
		if (l <= a && b <= r) return dat[u];
		if (r <= a || b <= l) return -(1LL << 60);
		long long v1 = query_(l, r, a, (a + b) >> 1, u * 2);
		long long v2 = query_(l, r, (a + b) >> 1, b, u * 2 + 1);
		return max(v1, v2);
	}
	long long query(int l, int r) {
		return query_(l, r, 0, size_, 1);
	}
};

long long W, N;
long long L[1 << 18], R[1 << 18], V[1 << 18];
long long dp[509][10009];
RangeMax Z[509];

int main() {
	// Step #1. 入力
	cin >> W >> N;
	for (int i = 1; i <= N; i++) cin >> L[i] >> R[i] >> V[i];

	// Step #2. 初期化
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= W; j++) dp[i][j] = -(1LL << 60);
		Z[i].init(W + 2);
	}
	dp[0][0] = 0;
	Z[0].update(0, 0);

	// Step #3. 動的計画法
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= W; j++) dp[i][j] = dp[i - 1][j];
		for (int j = 0; j <= W; j++) {
			int cl = max(0, j - (int)R[i]), cr = max(0, j - (int)L[i] + 1);
			if (cl == cr) continue;
			long long val = Z[i - 1].query(cl, cr);
			if (val != -(1LL << 60)) {
				dp[i][j] = max(dp[i][j], val + V[i]);
			}
		}
		for (int j = 0; j <= W; j++) Z[i].update(j, dp[i][j]);
	}

	// Step #4. 出力
	if (dp[N][W] == -(1LL << 60)) cout << "-1" << endl;
	else cout << dp[N][W] << endl;
	return 0;
}