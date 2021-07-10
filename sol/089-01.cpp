#include <iostream>
using namespace std;

long long mod = 1000000007;
long long N, K, Answer = 1;
long long A[1 << 18];

int main() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = 1; i <= N - 1; i++) {
		if (A[i] <= A[i + 1]) {
			Answer *= 2LL;
			Answer %= mod;
		}
	}
	cout << Answer << endl;
	return 0;
}