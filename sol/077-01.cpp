#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
using namespace std;

int N, T;
int AX[1 << 18], AY[1 << 18];
int BX[1 << 18], BY[1 << 18];
int power8[12];
int dx[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

bool check(vector<pair<int, int>> R, vector<pair<int, int>> S) {
	sort(R.begin(), R.end());
	sort(S.begin(), S.end());
	if (R == S) return true;
	return false;
}

int main() {
	// Step #1. Input
	cin >> N >> T;
	for (int i = 1; i <= N; i++) cin >> AX[i] >> AY[i];
	for (int i = 1; i <= N; i++) cin >> BX[i] >> BY[i];
	assert(N <= 6);

	// Step #2. Bit Zentansaku
	power8[0] = 1;
	for (int i = 1; i <= 11; i++) power8[i] = 8 * power8[i - 1];
	for (int i = 0; i < power8[N]; i++) {
		int bit[12];
		for (int j = 0; j < N; j++) bit[j + 1] = (i / power8[j]) % 8;

		vector<pair<int, int>> R, S;
		for (int j = 1; j <= N; j++) {
			int p = AX[j] + dx[bit[j]] * T;
			int q = AY[j] + dy[bit[j]] * T;
			S.push_back(make_pair(p, q));
			R.push_back(make_pair(BX[j], BY[j]));
		}
		if (check(R, S) == true) {
			cout << "Yes" << endl;
			for (int j = 1; j <= N; j++) {
				if (j >= 2) cout << " ";
				cout << bit[j] + 1;
			}
			cout << endl;
			return 0;
		}
	}

	cout << "No" << endl;
	return 0;
}