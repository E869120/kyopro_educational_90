#include <vector>
#include <iostream>
using namespace std;
const int mod = 998244353;
vector<vector<int> > matrix_mult(vector<vector<int> > A, vector<vector<int> > B) {
	int X = A.size(), Y = B.size(), Z = B[0].size();
	vector<vector<int> > ans(X, vector<int>(Z, 0));
	for (int i = 0; i < X; ++i) {
		for (int j = 0; j < Y; ++j) {
			for (int k = 0; k < Z; ++k) {
				ans[i][k] = (ans[i][k] + (long long)(A[i][j]) * B[j][k]) % mod;
			}
		}
	}
	return ans;
}
int main() {
	long long N; int K;
	cin >> N >> K;
	vector<vector<int> > matrix = { { 1, 1 }, { 1, 0 } };
	vector<vector<int> > answer = { { 1, 0 }, { 0, 1 } };
	long long b = N;
	while (b != 0) {
		if (b % 2 == 1) {
			answer = matrix_mult(answer, matrix);
		}
		matrix = matrix_mult(matrix, matrix);
		b /= 2;
	}
	cout << (answer[0][0] + answer[1][0]) % mod << endl;
	return 0;
}