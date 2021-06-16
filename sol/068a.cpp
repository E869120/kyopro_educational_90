#include <vector>
#include <iostream>
using namespace std;
class union_find {
private:
	int N;
	vector<int> par;
public:
	union_find() : N(0), par() {}
	union_find(int N_) : N(N_) {
		par.resize(N);
		for (int i = 0; i < N; ++i) {
			par[i] = i;
		}
	}
	int root(int x) {
		if (x == par[x]) return x;
		return par[x] = root(par[x]);
	}
	void link(int x, int y) {
		par[root(x)] = root(y);
	}
	bool connected(int x, int y) {
		return root(x) == root(y);
	}
};
int main() {
	int N, Q;
	cin >> N >> Q;
	vector<int> T(Q), X(Q), Y(Q), V(Q);
	for (int i = 0; i < Q; ++i) {
		cin >> T[i] >> X[i] >> Y[i] >> V[i];
		--X[i], --Y[i];
	}
	vector<int> sum(N - 1, 0);
	for (int i = 0; i < Q; ++i) {
		if (T[i] == 0) {
			sum[X[i]] = V[i];
		}
	}
	vector<long long> potential(N, 0);
	for (int i = 0; i < N - 1; ++i) {
		potential[i + 1] = sum[i] - potential[i];
	}
	union_find uf(N);
	for (int i = 0; i < Q; ++i) {
		if (T[i] == 0) {
			uf.link(X[i], Y[i]);
		}
		if (T[i] == 1) {
			if (!uf.connected(X[i], Y[i])) {
				cout << "Ambiguous" << endl;
			}
			else if ((X[i] + Y[i]) % 2 == 0) {
				cout << V[i] + (potential[Y[i]] - potential[X[i]]) << endl;
			}
			else {
				cout << (potential[X[i]] + potential[Y[i]]) - V[i] << endl;
			}
		}
	}
	return 0;
}