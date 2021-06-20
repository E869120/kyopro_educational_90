// Time Complexity: O((N + M + K) * K)

#include <vector>
#include <iostream>
#include <functional>
using namespace std;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N, M, K;
	cin >> N >> M >> K;
	vector<vector<int> > G(N);
	vector<int> deg(N);
	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b; --a, --b;
		G[a].push_back(b);
		++deg[b];
	}
	vector<int> st;
	vector<int> perm(N, -1);
	vector<vector<int> > answer_list;
	function<bool(int)> dfs = [&](int depth) {
		if (depth == N) {
			answer_list.push_back(perm);
			return true;
		}
		if (st.empty()) {
			return false;
		}
		for (int i = int(st.size()) - 1; i >= 0; --i) {
			if (answer_list.size() == K) {
				break;
			}
			int x = st[i];
			st.erase(st.begin() + i);
			for (int j : G[x]) {
				--deg[j];
				if (deg[j] == 0) {
					st.push_back(j);
				}
			}
			perm[depth] = x;
			bool sign = dfs(depth + 1);
			if (!sign) {
				return false;
			}
			for (int j : G[x]) {
				if (deg[j] == 0) {
					st.pop_back();
				}
				++deg[j];
			}
			st.insert(st.begin() + i, x);
		}
		return true;
	};
	for (int i = 0; i < N; ++i) {
		if (deg[i] == 0) {
			st.push_back(i);
		}
	}
	dfs(0);
	if (answer_list.size() != K) {
		cout << -1 << endl;
	}
	else {
		for (vector<int> v : answer_list) {
			for (int i = 0; i < N; ++i) {
				if (i != 0) cout << ' ';
				cout << v[i] + 1;
			}
			cout << endl;
		}
	}
	return 0;
}