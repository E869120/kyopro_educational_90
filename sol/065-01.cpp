#include <iostream>
#include <cassert>
using namespace std;

int R, G, B, K;
int X, Y, Z;

int main() {
	// Step #1. 入力・前処理
	cin >> R >> G >> B >> K;
	cin >> X >> Y >> Z;
	assert(R + G + B <= 15);

	// Step #2. bit 全探索
	int Answer = 0;
	for (int i = 0; i < (1 << (R + G + B)); i++) {
		int cntr = 0, cntg = 0, cntb = 0;
		for (int j = 0; j < R + G + B; j++) {
			if ((i & (1 << j)) == 0) continue;
			if (j < R) cntr += 1;
			else if (j < R + G) cntg += 1;
			else cntb += 1;
		}
		if (cntr + cntg <= X && cntg + cntb <= Y && cntb + cntr <= Z && cntr + cntg + cntb == K) {
			Answer += 1;
		}
	}

	// Srep #3. 出力
	cout << Answer << endl;
	return 0;
}