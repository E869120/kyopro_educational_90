#include <string>
#include <vector>
#include <iostream>
using namespace std;
int main() {
	int N, S;
	cin >> N >> S;
	vector<int> A(N), B(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i] >> B[i];
	}
	vector<vector<bool> > dp(N + 1, vector<bool>(S + 1, false));
	dp[0][0] = true;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j <= S; ++j) {
			if (j >= A[i] && dp[i][j - A[i]]) dp[i + 1][j] = true;
			if (j >= B[i] && dp[i][j - B[i]]) dp[i + 1][j] = true;
		}
	}
	if (!dp[N][S]) {
		cout << "Impossible" << endl;
	}
	else {
		string res(N, '?');
		int pos = S;
		for (int i = N - 1; i >= 0; --i) {
			if (pos >= B[i] && dp[i][pos - B[i]]) {
				res[i] = 'B';
				pos -= B[i];
			}
			else {
				res[i] = 'A';
				pos -= A[i];
			}
		}
		cout << res << endl;
	}
	return 0;
}