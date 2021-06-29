#include <cmath>
#include <vector>
#include <iostream>
using namespace std;
int main() {
	int H, W;
	cin >> H >> W;
	vector<vector<long long> > A(H, vector<long long>(W)), B(H, vector<long long>(W));
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			cin >> A[i][j];
		}
	}
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			cin >> B[i][j];
		}
	}
	long long ans = 0;
	for (int i = 0; i < H - 1; ++i) {
		for (int j = 0; j < W - 1; ++j) {
			int d = B[i][j] - A[i][j];
			A[i][j] += d;
			A[i][j + 1] += d;
			A[i + 1][j] += d;
			A[i + 1][j + 1] += d;
			ans += abs(d);
		}
	}
	if (A == B) {
		cout << "Yes" << endl;
		cout << ans << endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}