#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
bool check(int N, int K, vector<int> A) {
	for (int l = 0; l < N; ++l) {
		for (int r = l + 1; r <= N; ++r) {
			int rangemin = *min_element(A.begin() + l, A.begin() + r);
			if (rangemin * (r - l) > K) {
				return false;
			}
		}
	}
	return true;
}
int main() {
	int N, K;
	cin >> N >> K;
	int mul = 1;
	for (int i = 0; i < N; ++i) {
		mul *= (K + 1);
	}
	int ans = 0;
	for (int i = 0; i < mul; ++i) {
		vector<int> A(N);
		int x = i;
		for (int j = 0; j < N; ++j) {
			A[j] = x % (K + 1);
			x /= (K + 1);
		}
		if (check(N, K, A)) {
			++ans;
		}
	}
	cout << ans << endl;
	return 0;
}