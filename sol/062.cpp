#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N;
int A[1 << 18], B[1 << 18];
bool usable[1 << 18];
vector<int> G[1 << 18];
queue<int> Q;

int main() {
	// Step #1. 入力
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i] >> B[i];
		G[A[i]].push_back(i);
		G[B[i]].push_back(i);
		if (A[i] == i || B[i] == i) {
			usable[i] = true;
			Q.push(i);
		}
	}

	// Step #2. 後ろからシミュレーション
	vector<int> vec;
	while (!Q.empty()) {
		int pos = Q.front(); Q.pop();
		vec.push_back(pos);
		for (int i : G[pos]) {
			if (usable[i] == true) continue;
			usable[i] = true;
			Q.push(i);
		}
	}

	// Step #3. 答えを求める
	reverse(vec.begin(), vec.end());
	if (vec.size() != N) {
		cout << "-1" << endl;
	}
	else {
		for (int i = 0; i < vec.size(); i++) cout << vec[i] << endl;
	}
	return 0;
}