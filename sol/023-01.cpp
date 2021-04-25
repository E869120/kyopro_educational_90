#include <iostream>
using namespace std;

int H, W;
char c[25][25];
bool used[25][25];

bool hantei(int sx, int sy) {
	int dx[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
	int dy[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };
	for (int i = 0; i < 8; i++) {
		int tx = sx + dx[i];
		int ty = sy + dy[i];
		if (tx < 0 || ty < 0 || tx >= H || ty >= W) continue;
		if (used[tx][ty] == true) return false;
	}
	return true;
}

int dfs(int sx, int sy) {
	if (sx == H) return 1;

	int nx = sx, ny = sy + 1;
	if (ny == W) { nx += 1; ny = 0; }

	int ret1 = dfs(nx, ny);
	int ret2 = 0;
	if (hantei(sx, sy) == true && c[sx][sy] == '.') {
		used[sx][sy] = true;
		ret2 = dfs(nx, ny);
		used[sx][sy] = false;
	}
	return ret1 + ret2;
}

int main() {
	// Step #1. Input
	cin >> H >> W;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) cin >> c[i][j];
	}

	// Step #2. DFS
	int Answer = dfs(0, 0);
	cout << Answer << endl;
	return 0;
}