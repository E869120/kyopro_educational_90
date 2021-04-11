#include <iostream>
#include <algorithm>
using namespace std;

// 入力
long long N;
long long D[5009], C[5009], S[5009];

// 動的計画法
long long dp[5009][5009];

int main() {
	// Step #1. 入力
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> D[i] >> C[i] >> S[i];
	}

	// Step #2. 順列全探索
	int ord[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	long long Answer = 0;
	do {
		long long CurrentTime = 0;
		long long CurrentMoney = 0;
		for (int i = 0; i < N; i++) {
			if (CurrentTime + C[ord[i]] <= D[ord[i]]) {
				CurrentTime += C[ord[i]];
				CurrentMoney += S[ord[i]];
			}
			else {
				break; // これ以上仕事ができない
			}
		}
		Answer = max(Answer, CurrentMoney);
	} while (next_permutation(ord, ord + N));

	// Step #3. 出力
	cout << Answer << endl;
	return 0;
}