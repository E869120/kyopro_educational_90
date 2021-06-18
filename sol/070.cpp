#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<int> X(N), Y(N);
	for (int i = 0; i < N; ++i) {
		cin >> X[i] >> Y[i];
	}
	nth_element(X.begin(), X.begin() + N / 2, X.end());
	nth_element(Y.begin(), Y.begin() + N / 2, Y.end());
	long long ans = 0;
	for (int i = 0; i < N; ++i) {
		ans += abs(X[i] - X[N / 2]);
		ans += abs(Y[i] - Y[N / 2]);
	}
	cout << ans << endl;
	return 0;
}