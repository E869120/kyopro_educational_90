#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class BIT {
public:
	int size_ = 0;
	vector<long long> dat;
	
	void init(int sz) {
		size_ = sz + 2;
		dat.resize(size_ + 2, 0);
	}
	void add(int pos, long long x) {
		pos++;
		while (pos <= size_) {
			dat[pos] += x;
			pos += (pos & -pos);
		}
	}
	long long sum(int pos) {
		long long s = 0; pos++;
		while (pos >= 1) {
			s += dat[pos];
			pos -= (pos & -pos);
		}
		return s;
	}
};

long long N, K, mod = 1000000007;
long long A[1000009], cl[1000009];
long long dp[1000009], ru[1000009];
BIT Z;

int main() {
	// Step #1. Input
	cin >> N >> K;
	for (int i = 1; i <= N; i++) cin >> A[i];

	// Step #2. Coordinate Compression
	vector<long long> V;
	for (int i = 1; i <= N; i++) V.push_back(A[i]);
	sort(V.begin(), V.end());
	V.erase(unique(V.begin(), V.end()), V.end());
	for (int i = 1; i <= N; i++) A[i] = lower_bound(V.begin(), V.end(), A[i]) - V.begin();

	// Step #3. Maeshori
	long long l = N, cnt = 0;
	Z.init(V.size() + 2);
	Z.add(A[N], 1);
	for (int r = N; r >= 1; r--) {
		while (l >= 1 && cnt <= K) {
			l--;
			cnt += Z.sum(A[l] - 1);
			Z.add(A[l], 1);
		}
		Z.add(A[r], -1);
		cnt -= (Z.sum(V.size() + 1) - Z.sum(A[r]));
		cl[r] = l;
	}

	// Step #4. DP
	dp[0] = 1; ru[0] = 1;
	for (int i = 1; i <= N; i++) {
		if (cl[i] == 0) dp[i] = ru[i - 1];
		if (cl[i] >= 1) dp[i] = (ru[i - 1] - ru[cl[i] - 1] + mod) % mod;
		ru[i] = (ru[i - 1] + dp[i]) % mod;
	}
	cout << dp[N] << endl;
	return 0;
}