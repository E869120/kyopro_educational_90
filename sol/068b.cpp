#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
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
	vector<long long> pot(N, 0);
	for (int i = 0; i < N - 1; ++i) {
		pot[i + 1] = sum[i] - pot[i];
	}
	set<int> s;
	for (int i = -1; i < N; ++i) {
		s.insert(i);
	}
	for (int i = 0; i < Q; ++i) {
		if (T[i] == 0) {
			s.erase(X[i]);
		}
		else {
			int p = min(X[i], Y[i]), q = max(X[i], Y[i]);
			set<int>::iterator it = s.lower_bound(p);
			if (*it > q - 1) {
				cout << ((q - p) % 2 == 0 ? pot[Y[i]] + (V[i] - pot[X[i]]) : pot[Y[i]] - (V[i] - pot[X[i]])) << endl;
			}
			else {
				cout << "Ambiguous" << endl;
			}
		}
	}
	return 0;
}