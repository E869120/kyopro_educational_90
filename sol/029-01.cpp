#include <iostream>
#include <algorithm>
using namespace std;
int W, N, A[524288];
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> W >> N;
	for (int i = 0; i < N; ++i) {
		int L, R;
		cin >> L >> R; --L;
		int height = *max_element(A + L, A + R) + 1;
		fill(A + L, A + R, height);
		cout << height << '\n';
	}
	return 0;
}