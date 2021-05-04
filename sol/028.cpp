#include <iostream>
using namespace std;

// Input
int N;
int lx[1 << 18], ly[1 << 18], rx[1 << 18], ry[1 << 18];

// Count Number
int cnt[1009][1009];
int Answer[1 << 18];

int main() {
	// Step #1. Input
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> lx[i] >> ly[i] >> rx[i] >> ry[i];

	// Step #2. Imos Method in 2D
	for (int i = 1; i <= N; i++) {
		cnt[lx[i]][ly[i]] += 1;
		cnt[lx[i]][ry[i]] -= 1;
		cnt[rx[i]][ly[i]] -= 1;
		cnt[rx[i]][ry[i]] += 1;
	}
	for (int i = 0; i <= 1000; i++) {
		for (int j = 1; j <= 1000; j++) cnt[i][j] += cnt[i][j - 1];
	}
	for (int i = 1; i <= 1000; i++) {
		for (int j = 0; j <= 1000; j++) cnt[i][j] += cnt[i - 1][j];
	}

	// Step #3. Count Number
	for (int i = 0; i <= 1000; i++) {
		for (int j = 0; j <= 1000; j++) {
			if (cnt[i][j] >= 1) Answer[cnt[i][j]] += 1;
		}
	}

	// Step #4. Output The Answer
	for (int i = 1; i <= N; i++) cout << Answer[i] << endl;
	return 0;
}