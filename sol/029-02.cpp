#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int W, N;
	cin >> W >> N;
	vector<int> L(N), R(N);
	for (int i = 0; i < N; ++i) {
		cin >> L[i] >> R[i];
		--L[i];
	}
	vector<int> compression;
	for (int i = 0; i < N; ++i) {
		compression.push_back(L[i]);
		compression.push_back(R[i]);
	}
	sort(compression.begin(), compression.end());
	compression.erase(unique(compression.begin(), compression.end()), compression.end());
	for (int i = 0; i < N; ++i) {
		L[i] = lower_bound(compression.begin(), compression.end(), L[i]) - compression.begin();
		R[i] = lower_bound(compression.begin(), compression.end(), R[i]) - compression.begin();
	}
	vector<int> h(compression.size() - 1);
	for (int i = 0; i < N; ++i) {
		int height = *max_element(h.begin() + L[i], h.begin() + R[i]) + 1;
		fill(h.begin() + L[i], h.begin() + R[i], height);
		cout << height << '\n';
	}
	return 0;
}