#include <vector>
#include <iostream>
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<int> A(N), B(N), C(N);
	for (int i = 0; i < N; ++i) cin >> A[i];
	for (int i = 0; i < N; ++i) cin >> B[i];
	for (int i = 0; i < N; ++i) cin >> C[i];
	vector<int> am(46), bm(46), cm(46);
	for (int i = 0; i < N; ++i) {
		++am[A[i] % 46];
		++bm[B[i] % 46];
		++cm[C[i] % 46];
	}
	long long ans = 0;
	for (int i = 0; i < 46; ++i) {
		for (int j = 0; j < 46; ++j) {
			for (int k = 0; k < 46; ++k) {
				if ((i + j + k) % 46 == 0) {
					ans += (long long)(am[i]) * bm[j] * cm[k];
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}
