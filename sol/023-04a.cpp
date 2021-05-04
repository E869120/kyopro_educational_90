#include <iostream>
#include <string>
#include <map>
using namespace std;

// Input
int H, W;
char c[25][25];

// Map
int cnt[25];
bool used[25][25];
int nex0[25][1 << 18];
int nex1[25][1 << 18];
string state[25][1 << 18];
map<string, pair<int, bool>> Map[25];

// DP
int mod = 1000000007;
int dp[25][25][1 << 18];

bool hantei(int sx, int sy) {
	int dx[8] = { 1, 1, 1, 0, -1, -1, -1, 0 };
	int dy[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };
	for (int i = 0; i < 8; i++) {
		int tx = sx + dx[i], ty = sy + dy[i];
		if (tx < 0 || ty < 0 || ty >= W) continue;
		if (used[tx][ty] == true) return false;
	}
	return true;
}

void dfs(int pos, int dep, string str) {
	int sx = pos / W, sy = pos % W;
	if (dep == W + 1) {
		int idx = cnt[sy];
		bool flag = hantei(sx, sy);
		state[sy][idx] = str;
		Map[sy][str] = make_pair(idx, flag);
		cnt[sy] += 1;
		return;
	}

	dfs(pos + 1, dep + 1, str + "0");
	if (hantei(sx, sy) == true) {
		used[sx][sy] = true;
		dfs(pos + 1, dep + 1, str + "1");
		used[sx][sy] = false;
	}
}

int main() {
	// Step #1. Input
	cin >> H >> W;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) cin >> c[i][j];
	}

	// Step #2. Initialize
	for (int i = 0; i < W; i++) {
		dfs(i, 0, "");
	}
	for (int i = 0; i < W; i++) {
		for (int j = 0; j < cnt[i]; j++) {
			string t = state[i][j];
			string t0 = t.substr(1, t.size() - 1) + "0";
			string t1 = t.substr(1, t.size() - 1) + "1";
			nex0[i][j] = Map[(i + 1) % W][t0].first;
			if (Map[i][t].second == true) {
				nex1[i][j] = Map[(i + 1) % W][t1].first;
			}
			else {
				nex1[i][j] = -1;
			}
		}
	}

	// Step #3. DP
	dp[0][0][0] = 1;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			int n1 = i, n2 = j + 1;
			if (n2 == W) { n1 += 1; n2 = 0; }

			for (int k = 0; k < cnt[j]; k++) {
				if (dp[i][j][k] == 0) continue;
				dp[n1][n2][nex0[j][k]] += dp[i][j][k];
				dp[n1][n2][nex0[j][k]] %= mod;
				if (nex1[j][k] != -1 && c[i][j] == '.') {
					dp[n1][n2][nex1[j][k]] += dp[i][j][k];
					dp[n1][n2][nex1[j][k]] %= mod;
				}
			}
		}
	}

	// Step #4. Output The Answer
	int Answer = 0;
	for (int i = 0; i < cnt[0]; i++) {
		Answer += dp[H][0][i];
		Answer %= mod;
	}
	cout << Answer << endl;
	return 0;
}