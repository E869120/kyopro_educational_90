#include <iostream>
#include <vector>
#include <map>
#include <cassert>
using namespace std;

int N, T;
int AX[1 << 18], AY[1 << 18];
int BX[1 << 18], BY[1 << 18];
int Answer[1 << 18], cnta, cntb;
bool used[1 << 18];
vector<int> G[1 << 18];
map<int, int> Map;

void dfs(int pos, int pre) {
	used[pos] = true;
	if (pos <= N) cnta++;
	if (pos > N) {
		cntb++;
		if (AX[pre] < BX[pos - N]) Answer[pre] = 1;
		if (AX[pre] > BX[pos - N]) Answer[pre] = 5;
	}
	for (int i : G[pos]) {
		if (used[i] == true) continue;
		dfs(i, pos);
	}
}

int main() {
	// Step #1. Input
	cin >> N >> T;
	for (int i = 1; i <= N; i++) cin >> AX[i] >> AY[i];
	for (int i = 1; i <= N; i++) cin >> BX[i] >> BY[i];
	for (int i = 1; i <= N; i++) Map[BX[i]] = i;
	for (int i = 1; i <= N; i++) assert(AY[i] == 0);
	for (int i = 1; i <= N; i++) assert(BY[i] == 0);

	// Step #2. Make Graph
	for (int i = 1; i <= N; i++) {
		int idx1 = Map[AX[i] - T];
		int idx2 = Map[AX[i] + T];
		if (idx1 != 0) { G[i].push_back(idx1 + N); G[idx1 + N].push_back(i); }
		if (idx2 != 0) { G[i].push_back(idx2 + N); G[idx2 + N].push_back(i); }
	}

	// Step #3. DFS
	for (int i = 1; i <= N; i++) {
		if (G[i].size() >= 2 || used[i] == true) continue;
		cnta = 0; cntb = 0;
		dfs(i, -1);
		if (cnta != cntb) {
			cout << "No" << endl;
			return 0;
		}
	}

	// Step #4. Output
	cout << "Yes" << endl;
	for (int i = 1; i <= N; i++) {
		if (i >= 2) cout << " ";
		cout << Answer[i];
	}
	cout << endl;
	return 0;
}