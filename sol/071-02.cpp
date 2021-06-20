// Subtask: K = 1
// Time Complexity: O(N + M)

#include <queue>
#include <vector>
#include <cassert>
#include <iostream>
using namespace std;
int main() {
	int N, M, K;
	cin >> N >> M >> K;
	assert(K == 1);
	vector<vector<int> > G(N);
	vector<int> deg(N);
	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b; --a, --b;
		G[a].push_back(b);
		++deg[b];
	}
	queue<int> que;
	for (int i = 0; i < N; ++i) {
		if (deg[i] == 0) {
			que.push(i);
		}
	}
	vector<int> perm;
	while (!que.empty()) {
		int u = que.front(); que.pop();
		perm.push_back(u);
		for (int i : G[u]) {
			--deg[i];
			if (deg[i] == 0) {
				que.push(i);
			}
		}
	}
	if (perm.size() != N) {
		cout << -1 << endl;
	}
	else {
		for (int i = 0; i < N; ++i) {
			if (i != 0) cout << ' ';
			cout << perm[i] + 1;
		}
		cout << endl;
	}
	return 0;
}