#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
	int to, cap, rev;
};

class Ford_Fulkerson {
public:
	int size_ = 1;
	bool used[1 << 18];
	vector<Edge> G[1 << 18];

	void init(int sz) {
		size_ = sz;
	}
	void add_edge(int u, int v, int c) {
		G[u].push_back(Edge{ v, c, (int)G[v].size() });
		G[v].push_back(Edge{ u, 0, (int)G[u].size() - 1 });
	}
	int dfs(int pos, int to, int f) {
		if (pos == to) return f;
		used[pos] = true;
		for (int i = 0; i < G[pos].size(); i++) {
			if (used[G[pos][i].to] == true || G[pos][i].cap == 0) continue;
			int z = dfs(G[pos][i].to, to, min(f, G[pos][i].cap));
			if (z != 0) {
				G[pos][i].cap -= z;
				G[G[pos][i].to][G[pos][i].rev].cap += z;
				return z;
			}
		}
		return 0;
	}
	int max_flow(int s, int t) {
		int ret = 0;
		while (true) {
			for (int i = 0; i <= size_; i++) used[i] = false;
			int f = dfs(s, t, 1000000007);
			if (f == 0) break;
			ret += f;
		}
		return ret;
	}
};

int N, T;
int AX[1 << 18], AY[1 << 18];
int BX[1 << 18], BY[1 << 18];
int dx[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

map<pair<int, int>, int> Map;
int Nex[1 << 18][8];
int Answer[1 << 18];
Ford_Fulkerson Z;

int main() {
	// Step #1. Input
	cin >> N >> T;
	for (int i = 1; i <= N; i++) cin >> AX[i] >> AY[i];
	for (int i = 1; i <= N; i++) cin >> BX[i] >> BY[i];
	for (int i = 1; i <= N; i++) Map[make_pair(BX[i], BY[i])] = i;

	// Step #2. Add Edge
	Z.init(2 * N + 5);
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 8; j++) {
			int tx = AX[i] + dx[j] * T;
			int ty = AY[i] + dy[j] * T;
			Nex[i][j] = Map[make_pair(tx, ty)];
			if (Nex[i][j] != 0) {
				Z.add_edge(i, N + Nex[i][j], 1);
			}
		}
	}
	for (int i = 1; i <= N; i++) Z.add_edge(2 * N + 1, i, 1);
	for (int i = 1; i <= N; i++) Z.add_edge(i + N, 2 * N + 2, 1);

	// Step #3. Max Flow
	int res = Z.max_flow(2 * N + 1, 2 * N + 2);
	if (res != N) {
		cout << "No" << endl;
		return 0;
	}

	// Step #4. Get Answer
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < Z.G[i].size(); j++) {
			if (Z.G[i][j].to > 2 * N || Z.G[i][j].cap == 1) continue;
			for (int k = 0; k < 8; k++) {
				if (Nex[i][k] == Z.G[i][j].to - N) Answer[i] = k + 1;
			}
		}
	}

	// Step #5. Output
	cout << "Yes" << endl;
	for (int i = 1; i <= N; i++) {
		if (i >= 2) cout << " ";
		cout << Answer[i];
	}
	cout << endl;
	return 0;
}