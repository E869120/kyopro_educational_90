#include <iostream>
using namespace std;
#pragma warning (disable: 4996)

int N;
int A[1 << 18], B[1 << 18];

int grundy[55][1555];

void init() {
	for (int i = 0; i <= 50; i++) {
		for (int j = 0; j <= 1500; j++) {
			int mex[1555];
			for (int k = 0; k < 1555; k++) mex[k] = 0;
			if (i >= 1) {
				mex[grundy[i - 1][j + i]] = 1;
			}
			if (j >= 2) {
				for (int k = 1; k <= (j / 2); k++) mex[grundy[i][j - k]] = 1;
			}
			for (int k = 0; k < 1555; k++) {
				if (mex[k] == 0) { grundy[i][j] = k; break; }
			}
		}
	}
}

int main() {
	// Step #1. Input
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = 1; i <= N; i++) cin >> B[i];

	// Step #2. Initialize
	init();

	// Step #3. Get Answer
	int sum_xor = 0;
	for (int i = 1; i <= N; i++) {
		if (i == N) {
			i += 0;
		}
		sum_xor ^= grundy[A[i]][B[i]];
	}

	// Step #4. Output
	if (sum_xor != 0) cout << "First" << endl;
	if (sum_xor == 0) cout << "Second" << endl;
	return 0;
}