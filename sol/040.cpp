// Time Complexity: O(N^4 log W)

#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
const int inf = 1012345678;
class edge {
public:
	int to, cap, rev;
	edge() : to(-1), cap(0), rev(-1) {};
	edge(int to_, int cap_, int rev_) : to(to_), cap(cap_), rev(rev_) {};
};
bool find_augment(int pos, int tar, int step, vector<vector<edge> >& G, vector<bool>& vis) {
	if (pos == tar) return true;
	vis[pos] = true;
	for (edge& e : G[pos]) {
		if (!vis[e.to] && e.cap >= step) {
			bool res = find_augment(e.to, tar, step, G, vis);
			if (res) {
				e.cap -= step;
				G[e.to][e.rev].cap += step;
				return true;
			}
		}
	}
	return false;
}
int max_flow(int src, int tar, int maxstep, vector<vector<edge> >& G) {
	int flow = 0;
	int step = 1;
	while (step * 2 <= maxstep) {
		step *= 2;
	}
	while (true) {
		vector<bool> vis(G.size(), false);
		bool res = find_augment(src, tar, step, G, vis);
		if (!res) {
			if (step == 1) break;
			step >>= 1;
		}
		else {
			flow += step;
		}
	}
	return flow;
}
int main() {
	int N, W;
	cin >> N >> W;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<vector<edge> > G(N + 2);
	function<void(int, int, int)> add_edge = [&](int va, int vb, int cap) {
		G[va].push_back(edge(vb, cap, G[vb].size()));
		G[vb].push_back(edge(va, 0, G[va].size() - 1));
	};
	for (int i = 1; i <= N; ++i) {
		int K, c;
		cin >> K;
		for (int j = 0; j < K; ++j) {
			cin >> c;
			add_edge(c, i, inf);
		}
	}
	for (int i = 1; i <= N; ++i) {
		add_edge(0, i, A[i - 1]);
		add_edge(i, N + 1, W);
	}
	int res = max_flow(0, N + 1, W, G);
	int answer = -res;
	for (int i = 0; i < N; ++i) {
		answer += A[i];
	}
	cout << answer << endl;
	return 0;
}