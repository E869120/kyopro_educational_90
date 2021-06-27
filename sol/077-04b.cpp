#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
#include <atcoder/maxflow>
using namespace std;
#pragma warning (disable: 4996)

int N, T;
int AX[1 << 18], AY[1 << 18];
int BX[1 << 18], BY[1 << 18];
int dx[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

map<pair<int, int>, int> Map;
int Nex[1 << 18][8];
int Answer[1 << 18];

int main() {
	// Step #1. Input
	cin >> N >> T;
	for (int i = 1; i <= N; i++) scanf("%d%d", &AX[i], &AY[i]);
	for (int i = 1; i <= N; i++) scanf("%d%d", &BX[i], &BY[i]);
	for (int i = 1; i <= N; i++) Map[make_pair(BX[i], BY[i])] = i;

	// Step #2. Add Edge
	atcoder::mf_graph<int> Z(2 * N + 5);
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 8; j++) {
			int tx = AX[i] + dx[j] * T;
			int ty = AY[i] + dy[j] * T;
			Nex[i][j] = Map[make_pair(tx, ty)];
			if (Nex[i][j] != 0) {
				Z.add_edge(i, N + Nex[i][j], 1);
			}
		}
	}
	for (int i = 1; i <= N; i++) Z.add_edge(2 * N + 1, i, 1);
	for (int i = 1; i <= N; i++) Z.add_edge(i + N, 2 * N + 2, 1);

	// Step #3. Max Flow
	int res = Z.flow(2 * N + 1, 2 * N + 2);
	if (res != N) {
		cout << "No" << endl;
		return 0;
	}

	// Step #4. Get Answer
	for (auto e : Z.edges()) {
		if (e.flow == 1) {
			int a = e.to;
			int b = e.from;
			if (!(a >= N + 1 && a <= 2 * N)) continue;
			if (!(b >= 1 && b <= N)) continue;
			for (int k = 0; k < 8; k++) {
				if (Nex[b][k] == a - N) Answer[b] = k + 1;
			}
		}
	}

	// Step #5. Output
	cout << "Yes" << endl;
	for (int i = 1; i <= N; i++) {
		if (i >= 2) cout << " ";
		cout << Answer[i];
	}
	cout << endl;
	return 0;
}