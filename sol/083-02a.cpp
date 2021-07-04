#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int N, M, Q;
	cin >> N >> M;
	vector<vector<int> > G(N);
	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b; --a, --b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	cin >> Q;
	vector<int> x(Q), y(Q);
	for (int i = 0; i < Q; ++i) {
		cin >> x[i] >> y[i]; --x[i];
	}
	int B = int(sqrt(2 * M));
	vector<int> large;
	for (int i = 0; i < N; ++i) {
		if (G[i].size() >= B) {
			large.push_back(i);
		}
	}
	vector<vector<bool> > link(N, vector<bool>(large.size(), false));
	for (int i = 0; i < large.size(); ++i) {
		for (int j : G[large[i]]) {
			link[j][i] = true;
		}
		link[large[i]][i] = true;
	}
	vector<int> update(N, -1);
	vector<int> update_large(large.size(), -1);
	for (int i = 0; i < Q; ++i) {
		int last = update[x[i]];
		for (int j = 0; j < large.size(); ++j) {
			if (link[x[i]][j]) {
				last = max(last, update_large[j]);
			}
		}
		cout << (last != -1 ? y[last] : 1) << endl;
		if (G[x[i]].size() < B) {
			update[x[i]] = i;
			for (int j : G[x[i]]) {
				update[j] = i;
			}
		}
		else {
			int ptr = find(large.begin(), large.end(), x[i]) - large.begin();
			update_large[ptr] = i;
		}
	}
	return 0;
}