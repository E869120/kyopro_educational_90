#include <vector>
#include <iostream>
using namespace std;
int digit_sum(int x) {
	int ans = 0;
	while (x > 0) {
		ans += x % 10;
		x /= 10;
	}
	return ans;
}
int main() {
	const int mod = 100000;
	int N; long long K;
	cin >> N >> K;
	vector<int> nxt(mod);
	for (int i = 0; i < mod; ++i) {
		nxt[i] = (i + digit_sum(i)) % mod;
	}
	vector<int> time_stamp(mod, -1);
	int pos = N, cnt = 0;
	while (time_stamp[pos] == -1) {
		time_stamp[pos] = cnt;
		pos = nxt[pos];
		++cnt;
	}
	int cycle = cnt - time_stamp[pos];
	if (K >= time_stamp[pos]) {
		K = (K - time_stamp[pos]) % cycle + time_stamp[pos];
	}
	int answer = -1;
	for (int i = 0; i < mod; ++i) {
		if (time_stamp[i] == K) {
			answer = i;
		}
	}
	cout << answer << endl;
	return 0;
}