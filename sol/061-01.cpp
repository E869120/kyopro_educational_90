#include <iostream>
using namespace std;

int Q, T[1 << 20], X[1 << 20];
int A[1 << 20];
int cl = 500000, cr = 500000;

int main() {
	// Step #1. 入力
	cin >> Q;
	for (int i = 1; i <= Q; i++) cin >> T[i] >> X[i];

	// Step #2. シミュレーション
	for (int i = 1; i <= Q; i++) {
		if (T[i] == 1) {
			cl--;
			A[cl] = X[i];
		}
		if (T[i] == 2) {
			A[cr] = X[i];
			cr++;
		}
		if (T[i] == 3) {
			cout << A[cl + X[i] - 1] << endl;
		}
	}
	return 0;
}