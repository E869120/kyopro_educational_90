#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
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

	// Step #2. D[i] の昇順にソート
	vector<tuple<long long, long long, long long>> tup;
	for (int i = 1; i <= N; i++) {
		tup.push_back(make_tuple(D[i], C[i], S[i]));
	}
	sort(tup.begin(), tup.end());
	for (int i = 1; i <= N; i++) {
		D[i] = get<0>(tup[i - 1]);
		C[i] = get<1>(tup[i - 1]);
		S[i] = get<2>(tup[i - 1]);
	}

	// Step #3. 動的計画法
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= 5000; j++) {
			// 仕事 i + 1 をやらない場合
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
			// 仕事 i + 1 をやる場合
			if (j + C[i + 1] <= D[i + 1]) {
				dp[i + 1][j + C[i + 1]] = max(dp[i + 1][j + C[i + 1]], dp[i][j] + S[i + 1]);
			}
		}
	}

	// Step #4. 出力
	long long Answer = 0;
	for (int i = 0; i <= 5000; i++) Answer = max(Answer, dp[N][i]);
	cout << Answer << endl;
	return 0;
}