#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Input
int N, M;
int A[12][12];
int X[1 << 18], Y[1 << 18];

// Other Variables
bool kenaku[12][12];
int Answer = (1 << 30);

int main() {
	// Step #1. Input
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) cin >> A[i][j];
	}
	cin >> M;
	for (int i = 1; i <= M; i++) cin >> X[i] >> Y[i];

	// Step #2. Init
	vector<int> vec;
	for (int i = 1; i <= N; i++) vec.push_back(i);
	for (int i = 1; i <= M; i++) {
		kenaku[X[i]][Y[i]] = true;
		kenaku[Y[i]][X[i]] = true;
	}

	// Step #3. Brute Force
	do {
		bool flag = true;
		int sum = 0;
		for (int i = 0; i < N - 1; i++) {
			if (kenaku[vec[i]][vec[i + 1]] == true) flag = false;
		}
		for (int i = 0; i < N; i++) sum += A[vec[i]][i + 1];
		if (flag == true) Answer = min(Answer, sum);

	} while (next_permutation(vec.begin(), vec.end()));

	// Step #4. Output The Answer
	if (Answer == (1 << 30)) Answer = -1;
	cout << Answer << endl;
	return 0;
}