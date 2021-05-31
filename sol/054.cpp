#include <queue>
#include <vector>
#include <iostream>
using namespace std;
int main() {
	int N, M;
	cin >> N >> M;
	vector<vector<int> > G(N + M);
	for (int i = 0; i < M; ++i) {
		int k, v;
		cin >> k;
		for (int j = 0; j < k; ++j) {
			cin >> v; --v;
			G[v].push_back(N + i);
			G[N + i].push_back(v);
		}
	}
	queue<int> que;
	que.push(0);
	vector<int> dist(N + M, -2);
	dist[0] = 0;
	while (!que.empty()) {
		int u = que.front(); que.pop();
		for (int i : G[u]) {
			if (dist[i] == -2) {
				dist[i] = dist[u] + 1;
				que.push(i);
			}
		}
	}
	for (int i = 0; i < N; ++i) {
		cout << dist[i] / 2 << '\n';
	}
	return 0;
}