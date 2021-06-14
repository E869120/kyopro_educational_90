// Time Complexity: O(N^2 * (maxR - minL)^2)

#include <vector>
#include <iostream>
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<int> L(N), R(N);
	for (int i = 0; i < N; ++i) {
		cin >> L[i] >> R[i];
	}
	double expsum = 0.0;
	for (int i = 0; i < N; ++i) {
		for (int j = i + 1; j < N; ++j) {
			int cnt = 0, all = 0;
			for (int k = L[i]; k <= R[i]; ++k) {
				for (int l = L[j]; l <= R[j]; ++l) {
					if (k > l) ++cnt;
					++all;
				}
			}
			expsum += double(cnt) / all;
		}
	}
	cout.precision(15);
	cout << fixed << expsum << endl;
	return 0;
}