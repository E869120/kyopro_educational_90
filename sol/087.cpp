#include <iostream>
#include <algorithm>
using namespace std;

long long N, P, K, A[69][69];
long long dist[69][69];

int count_number(long long lens) {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (A[i][j] == -1) dist[i][j] = lens;
			if (A[i][j] != -1) dist[i][j] = A[i][j];
		}
	}
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
		}
	}
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			if (dist[i][j] <= P) cnt++;
		}
	}
	return cnt;
}

long long get_border(long long cnts) {
	long long cl = 1, cr = 5000000000LL, cm, minx = 5000000000LL;
	for (int i = 0; i < 40; i++) {
		cm = (cl + cr) / 2LL;
		int res = count_number(cm);
		if (res <= cnts) { cr = cm; minx = min(minx, cm); }
		else { cl = cm; }
	}
	return minx;
}

int main() {
	cin >> N >> P >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) cin >> A[i][j];
	}

	long long L = get_border(K);
	long long R = get_border(K - 1);
	if (R - L >= 2000000000LL) cout << "Infinity" << endl;
	else cout << R - L << endl;
	return 0;
}