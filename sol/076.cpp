#include <iostream>
using namespace std;

long long N, A[1 << 19];
long long B[1 << 19];

int main() {
	// Step #1. Input
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];

	// Step #2. Make Array B
	for (int i = 1; i <= N; i++) B[i] = B[i - 1] + A[i];
	for (int i = 1; i <= N; i++) B[i + N] = B[i + N - 1] + A[i];
	if (B[N] % 10LL != 0LL) {
		cout << "No" << endl;
		return 0;
	}

	// Step #3. Get Answer
	for (int i = 0; i <= N; i++) {
		long long goal = B[i] + B[N] / 10LL;
		int pos1 = lower_bound(B, B + 2 * N + 1, goal) - B;
		if (B[pos1] == goal) {
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}