#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int N, K;
	cin >> N >> K;
	vector<int> A(N), B(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i] >> B[i];
	}
	int R = max(*max_element(A.begin(), A.end()), K) + 1;
	int C = max(*max_element(B.begin(), B.end()), K) + 1;
	vector<vector<int> > sum(R + 1, vector<int>(C + 1));
	for (int i = 0; i < N; ++i) {
		++sum[A[i] + 1][B[i] + 1];
	}
	for (int i = 1; i <= R; ++i) {
		for (int j = 1; j <= C; ++j) {
			sum[i][j] += sum[i - 1][j];
		}
	}
	for (int i = 1; i <= R; ++i) {
		for (int j = 1; j <= C; ++j) {
			sum[i][j] += sum[i][j - 1];
		}
	}
	int answer = 0;
	for (int i = 0; i <= R - K - 1; ++i) {
		for (int j = 0; j <= C - K - 1; ++j) {
			answer = max(answer, sum[i][j] + sum[i + K + 1][j + K + 1] - sum[i][j + K + 1] - sum[i + K + 1][j]);
		}
	}
	cout << answer << endl;
	return 0;
}