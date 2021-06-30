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
	long long answer = 0;
	for (int i = 0; i < (1 << N); ++i) {
		long long bit = 0;
		int conditions = 0;
		for (int j = 0; j < N; ++j) {
			if ((i >> j) & 1) {
				bit |= A[j];
				++conditions;
			}
		}
		int free_digits = 0;
		for (int j = 0; j < D; ++j) {
			if (((bit >> j) & 1) == 0) {
				++free_digits;
			}
		}
		if (conditions % 2 == 0) {
			answer += (1LL << free_digits);
		}
		else {
			answer -= (1LL << free_digits);
		}
	}
	cout << answer << endl;
	return 0;
}