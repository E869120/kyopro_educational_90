#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int mod = 1000000007;
int binpower(int a, long long b) {
	int ans = 1;
	while (b != 0) {
		if (b % 2 == 1) {
			ans = (long long)(ans)*a % mod;
		}
		a = (long long)(a)*a % mod;
		b /= 2;
	}
	return ans;
}
int main() {
	long long N; int K;
	cin >> N >> K;
	if (K == 1) {
		cout << (N == 1 ? 1 : 0) << endl;
	}
	else if (N == 1) {
		cout << K % mod << endl;
	}
	else if (N == 2) {
		cout << (long long)(K) * (K - 1) % mod << endl;
	}
	else {
		cout << (long long)(K) * (K - 1) % mod * binpower(K - 2, N - 2) % mod << endl;
	}
	return 0;
}