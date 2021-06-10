#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int H, W;
int P[19][10009];

int maximum_same(vector<int> R) {
	map<int, int> Map; int ret = 0;
	for (int i = 0; i < R.size(); i++) {
		Map[R[i]] += 1;
		ret = max(ret, Map[R[i]]);
	}
	return ret;
}

int main() {
	// Step #1. ì¸óÕ
	cin >> H >> W;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) cin >> P[i][j];
	}

	// Step #2. ëSíTçı
	int Answer = 0;
	for (int i = 1; i < (1 << H); i++) {
		vector<int> R;
		for (int j = 0; j < W; j++) {
			int idx = -1; bool flag = false;
			for (int k = 0; k < H; k++) {
				if ((i & (1 << k)) == 0) continue;
				if (idx == -1) idx = P[k][j];
				else if (idx != P[k][j]) flag = true;
			}
			if (flag == false) R.push_back(idx);
		}

		int cntH = 0, cntW = maximum_same(R);
		for (int j = 0; j < H; j++) {
			if ((i & (1 << j)) != 0) cntH += 1;
		}
		Answer = max(Answer, cntH * cntW);
	}
	cout << Answer << endl;
	return 0;
}