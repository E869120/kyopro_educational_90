#include <iostream>
#include <vector>
using namespace std;

// Input
int N, A[10007];
int Q, X[10007], Y[10007];

// Other Variables
int c[10007];
vector<int> G[10007];
vector<int> vec;
vector<vector<int>> Answer[10007];
bool flag = false;

void dfs(int pos, int dep) {
	if (flag == true) return;
	if (pos == N + 1) {
		Answer[dep].push_back(vec);
		if (Answer[dep].size() == 2) flag = true;
		return;
	}

	// Don't Choose
	dfs(pos + 1, dep);

	// Choose
	if (c[pos] == 0) {
		vec.push_back(pos);
		for (int i : G[pos]) c[i]++;
		dfs(pos + 1, dep + A[pos]);
		for (int i : G[pos]) c[i]--;
		vec.pop_back();
	}
}

int main() {
	// Step #1. Input
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = 1; i <= Q; i++) cin >> X[i] >> Y[i];
	for (int i = 1; i <= Q; i++) G[X[i]].push_back(Y[i]);

	// Step #2. DFS
	dfs(1, 0);

	// Step #3. Output The Answer
	for (int i = 0; i <= 10000; i++) {
		if (Answer[i].size() <= 1) continue;
		cout << Answer[i][0].size() << endl; 
		for (int j = 0; j < Answer[i][0].size(); j++) { if (j != 0) cout << " "; cout << Answer[i][0][j]; } cout << endl;
		cout << Answer[i][1].size() << endl;
		for (int j = 0; j < Answer[i][1].size(); j++) { if (j != 0) cout << " "; cout << Answer[i][1][j]; } cout << endl;
		return 0;
	}
	return 0;
}