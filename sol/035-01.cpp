#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<vector<int> > G(N);
	for (int i = 0; i < N - 1; ++i) {
		int A, B;
		cin >> A >> B; --A, --B;
		G[A].push_back(B);
		G[B].push_back(A);
	}
	int Q;
	cin >> Q;
	for (int i = 0; i < Q; ++i) {
		int verts;
		cin >> verts;
		vector<int> sel(verts);
		for (int j = 0; j < verts; ++j) {
			cin >> sel[j]; --sel[j];
		}
		vector<int> c(N);
		for (int j = 0; j < verts; ++j) {
			++c[sel[j]];
		}
		function<void(int, int)> tree_dp = [&](int pos, int pre) {
			for (int i : G[pos]) {
				if (i == pre) continue;
				tree_dp(i, pos);
				c[pos] += c[i];
			}
		};
		tree_dp(sel[0], -1);
		int need = 0;
		for (int i = 0; i < N; ++i) {
			if (i != sel[0] && c[i] != 0) {
				++need;
			}
		}
		cout << need << '\n';
	}
	return 0;
}