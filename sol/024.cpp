#include <iostream>
#include <cmath>
using namespace std;

long long N, K;
long long A[1 << 18], B[1 << 18];

int main() {
	// Step #1. Input
	cin >> N >> K;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = 1; i <= N; i++) cin >> B[i];

	// Step #2. Check Difference
	long long Diff = 0;
	for (int i = 1; i <= N; i++) Diff += abs(A[i] - B[i]);
	if (Diff > K) {
		cout << "No" << endl;
		return 0;
	}

	// Step #3. Check Parity
	if (Diff % 2 != K % 2) {
		cout << "No" << endl;
		return 0;
	}

	// Step #4. Output Yes
	cout << "Yes" << endl;
	return 0;
}