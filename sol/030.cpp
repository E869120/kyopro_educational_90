#include <iostream>
using namespace std;

int N, K;
int cnt[1 << 24];

int main() {
	// Step #1. Input
	cin >> N >> K;

	// Step #2. Count Number
	for (int i = 2; i <= N; i++) {
		if (cnt[i] >= 1) continue;
		for (int j = i; j <= N; j += i) cnt[j] += 1;
	}

	// Step #3. Get Answer
	int Answer = 0;
	for (int i = 1; i <= N; i++) {
		if (cnt[i] >= K) Answer += 1;
	}
	cout << Answer << endl;
	return 0;
}