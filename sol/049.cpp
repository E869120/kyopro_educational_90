#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

class UnionFind {
public:
	vector<int> par;

	void init(int sz) {
		par.resize(sz, -1);
	}
	int root(int pos) {
		if (par[pos] == -1) return pos;
		par[pos] = root(par[pos]);
		return par[pos];
	}
	void unite(int u, int v) {
		u = root(u); v = root(v);
		if (u == v) return;
		par[u] = v;
	}
	bool same(int u, int v) {
		if (root(u) == root(v)) return true;
		return false;
	}
};

long long N, M;
long long C[1 << 19], L[1 << 19], R[1 << 19];

int main() {
	// Step #1. 入力
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		cin >> C[i] >> L[i] >> R[i];
	}

	// Step #2. ソート
	vector<tuple<long long, int, int>> tup;
	for (int i = 1; i <= M; i++) tup.push_back(make_tuple(C[i], L[i] - 1, R[i]));
	sort(tup.begin(), tup.end());

	// Step #3. 最小全域木を求める
	long long cnt1 = 0, cnt2 = 0;
	UnionFind UF;
	UF.init(N + 2);
	for (int i = 0; i < tup.size(); i++) {
		int u = get<1>(tup[i]);
		int v = get<2>(tup[i]);
		if (UF.same(u, v) == false) {
			UF.unite(u, v);
			cnt1 += get<0>(tup[i]);
			cnt2 += 1;
		}
	}

	// Step #4. 出力
	if (cnt2 != N) cout << "-1" << endl;
	else cout << cnt1 << endl;
	return 0;
}