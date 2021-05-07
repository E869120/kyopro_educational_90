#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int N, K;
int A[1 << 18];
int Answer = 0;
map<int, int> Map;

int main() {
	// Step #1. Input
	cin >> N >> K;
	for (int i = 1; i <= N; i++) cin >> A[i];

	// Step #2. Shakutori
	int cr = 1, cnt = 0;
	for (int i = 1; i <= N; i++) {
		while (cr <= N) {
			if (Map[A[cr]] == 0 && cnt == K) break;
			if (Map[A[cr]] == 0) cnt++;
			Map[A[cr]] += 1;
			cr++;
		}
		Answer = max(Answer, cr - i);
		if (Map[A[i]] == 1) cnt--;
		Map[A[i]] -= 1;
	}

	// Step #3. Output The Answer
	cout << Answer << endl;
	return 0;
}