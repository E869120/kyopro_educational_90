#include <string>
#include <vector>
#include <iostream>
using namespace std;
int main() {
	int N; string S, T;
	cin >> N >> S >> T;
	vector<string> F(N);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (S[i] == T[j]) {
				// color: same as S[i] and T[j]
				F[i] += S[i];
			}
			else {
				// color: different from S[i] and T[j]
				F[i] += (S[i] ^ T[j] ^ 'R' ^ 'G' ^ 'B');
			}
		}
	}
	int answer = 0;
	for (int i = -(N - 1); i <= (N - 1); ++i) {
		int rcnt = 0, gcnt = 0, bcnt = 0;
		for (int r = 0; r < N; ++r) {
			int c = r + i;
			if (0 <= c && c < N) {
				if (F[r][c] == 'R') ++rcnt;
				if (F[r][c] == 'G') ++gcnt;
				if (F[r][c] == 'B') ++bcnt;
			}
		}
		if (rcnt == 0 && gcnt == 0) ++answer;
		if (gcnt == 0 && bcnt == 0) ++answer;
		if (bcnt == 0 && rcnt == 0) ++answer;
	}
	cout << answer << endl;
	return 0;
}