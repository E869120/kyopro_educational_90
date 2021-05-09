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
	int bits = 0;
	while ((1 << bits) < N) ++bits;
	vector<vector<int> > par(bits, vector<int>(N));
	vector<int> depth(N);
	function<void(int, int)> build_tree = [&](int pos, int pre) {
		par[0][pos] = pre;
		for (int i : G[pos]) {
			if (i == pre) continue;
			depth[i] = depth[pos] + 1;
			build_tree(i, pos);
		}
	};
	build_tree(0, 0);
	for (int i = 1; i < bits; ++i) {
		for (int j = 0; j < N; ++j) {
			par[i][j] = par[i - 1][par[i - 1][j]];
		}
	}
	function<int(int, int)> lca = [&](int va, int vb) {
		if (depth[va] < depth[vb]) swap(va, vb);
		for (int i = bits - 1; i >= 0; --i) {
			if (depth[va] - depth[vb] >= (1 << i)) {
				va = par[i][va];
			}
		}
		if (va == vb) return va;
		for (int i = bits - 1; i >= 0; --i) {
			if (par[i][va] != par[i][vb]) {
				va = par[i][va];
				vb = par[i][vb];
			}
		}
		return par[0][va];
	};
	int Q;
	cin >> Q;
	for (int i = 0; i < Q; ++i) {
		int verts;
		cin >> verts;
		if (verts == 3) {
			int va, vb, vc;
			cin >> va >> vb >> vc; --va, --vb, --vc;
			int vx = lca(va, vb);
			int vy = lca(vb, vc);
			int vz = lca(vc, va);
			cout << depth[va] + depth[vb] + depth[vc] - depth[vx] - depth[vy] - depth[vz] << '\n';
		}
	}
	return 0;
}