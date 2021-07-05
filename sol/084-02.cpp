#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

long long N, A[1 << 20], B[1 << 20];
string S;

int main() {
	cin >> N >> S;
	for (int i = 1; i <= N; i++) {
		if (S[i - 1] == 'o') { A[i] = i; B[i] = B[i - 1]; }
		if (S[i - 1] == 'x') { A[i] = A[i - 1]; B[i] = i; }
	}

	long long Answer = 0;
	for (int i = 1; i <= N; i++) {
		Answer += 1LL * min(A[i], B[i]);
	}
	cout << Answer << endl;
	return 0;
}