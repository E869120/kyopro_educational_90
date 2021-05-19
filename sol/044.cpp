#include <vector>
#include <iostream>
using namespace std;
int main() {
	int N, Q;
	cin >> N >> Q;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	int shifts = 0;
	for (int i = 0; i < Q; ++i) {
		int T, x, y;
		cin >> T >> x >> y;
		if (T == 1) {
			--x; --y;
			swap(A[(x + shifts) % N], A[(y + shifts) % N]);
		}
		if (T == 2) {
			shifts = (shifts + N - 1) % N;
		}
		if (T == 3) {
			--x;
			cout << A[(x + shifts) % N] << endl;
		}
	}
	return 0;
}