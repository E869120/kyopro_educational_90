#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

long long N, X[1 << 18], Y[1 << 18];
long long Q, T[1 << 18];
long long min_X = (1LL << 60), max_X = -(1LL << 60);
long long min_Y = (1LL << 60), max_Y = -(1LL << 60);

int main() {
	// Step #1. “ü—Í
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) cin >> X[i] >> Y[i];
	for (int i = 1; i <= Q; i++) cin >> T[i];

	// Step #2. 45 “x‰ñ“]
	for (int i = 1; i <= N; i++) {
		long long p1 = X[i] + Y[i];
		long long p2 = Y[i] - X[i];
		X[i] = p1;
		Y[i] = p2;
		min_X = min(min_X, X[i]);
		max_X = max(max_X, X[i]);
		min_Y = min(min_Y, Y[i]);
		max_Y = max(max_Y, Y[i]);
	}

	// Step #3. ƒNƒGƒŠ‚É“š‚¦‚é
	for (int i = 1; i <= Q; i++) {
		long long ret1 = abs(X[T[i]] - min_X);
		long long ret2 = abs(X[T[i]] - max_X);
		long long ret3 = abs(Y[T[i]] - min_Y);
		long long ret4 = abs(Y[T[i]] - max_Y);
		cout << max({ ret1, ret2, ret3, ret4 }) << endl;
	}
	return 0;
}