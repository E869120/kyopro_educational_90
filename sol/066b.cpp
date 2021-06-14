// Time Complexity: O(N^2)

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
double calc(int la, int ra, int lb, int rb) {
	++ra; ++rb;
	vector<int> sep = { la, ra, lb, rb };
	sort(sep.begin(), sep.end());
	sep.erase(unique(sep.begin(), sep.end()), sep.end());
	long long all = 0, cnt = 0;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (la <= sep[i] && sep[i + 1] <= ra && lb <= sep[j] && sep[j + 1] <= rb) {
				all += 1LL * (sep[i + 1] - sep[i]) * (sep[j + 1] - sep[j]);
				if (i > j) {
					cnt += 1LL * (sep[i + 1] - sep[i]) * (sep[j + 1] - sep[j]);
				}
				else if (i == j) {
					cnt += 1LL * (sep[i + 1] - sep[i]) * (sep[i + 1] - sep[i] - 1) / 2;
				}
			}
		}
	}
	return double(cnt) / all;
}
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
			expsum += calc(L[i], R[i], L[j], R[j]);
		}
	}
	cout.precision(15);
	cout << fixed << expsum << endl;
	return 0;
}