#include <iostream>
#include <algorithm>
using namespace std;

int H, W;
char c[20][20];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
bool used[20][20];

int dfs(int sx, int sy, int px, int py) {
	if (sx == px && sy == py && used[px][py] == true) return 0;
	used[px][py] = true;

	int ret = -10000;
	for (int i = 0; i < 4; i++) {
		int nx = px + dx[i], ny = py + dy[i];
		if (nx < 1 || ny < 1 || nx > H || ny > W || c[nx][ny] == '#') continue;
		if ((sx != nx || sy != ny) && used[nx][ny] == true) continue;
		int v = dfs(sx, sy, nx, ny);
		ret = max(ret, v + 1);
	}
	used[px][py] = false;
	return ret;
}

int main() {
	// Step #1. Input
	cin >> H >> W;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) cin >> c[i][j];
	}

	// Step #2. DFS
	int Answer = -1;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			Answer = max(Answer, dfs(i, j, i, j));
		}
	}
	if (Answer <= 2) Answer = -1;
	cout << Answer << endl;
	return 0;
}