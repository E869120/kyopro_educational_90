#include <vector>
#include <iostream>
using namespace std;
int main() {
	int N, D;
	cin >> N >> D;
	vector<long long> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<int> pop(1 << N);
	vector<long long> bit(1 << N);
	for (int i = 1; i < (1 << N); ++i) {
		pop[i] = pop[i >> 1] + (i & 1);
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < (1 << i); ++j) {
			bit[j + (1 << i)] = bit[j] | A[i];
		}
	}
	long long answer = 0;
	for (int i = 0; i < (1 << N); ++i) {
		int free_digits = D - __builtin_popcountll(bit[i]);
		if (pop[i] % 2 == 0) {
			answer += (1LL << free_digits);
		}
		else {
			answer -= (1LL << free_digits);
		}
	}
	cout << answer << endl;
	return 0;
}