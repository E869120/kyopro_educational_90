#include <vector>
#include <iostream>
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
	vector<int> col(N, 1);
	for (int i = 0; i < Q; ++i) {
		int x, y;
		cin >> x >> y; --x;
		cout << col[x] << endl;
		col[x] = y;
		for (int j : G[x]) {
			col[j] = y;
		}
	}
	return 0;
}