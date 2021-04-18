#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int L[1 << 18], R[1 << 18];

int main() {
	// Step #1. Input
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		cin >> L[i] >> R[i];
	}

	// Step #2. Brute Force
	int Answer = 0;
	for (int i = 1; i <= M; i++) {
		for (int j = i + 1; j <= M; j++) {
			if (L[i] == L[j] || L[i] == R[j] || R[i] == L[j] || R[i] == R[j]) continue;
			vector<pair<int, int>> vec;
			vec.push_back(make_pair(L[i], 1));
			vec.push_back(make_pair(R[i], 1));
			vec.push_back(make_pair(L[j], 2));
			vec.push_back(make_pair(R[j], 2));
			sort(vec.begin(), vec.end());
			if (vec[0].second == 1 && vec[1].second == 2 && vec[2].second == 1 && vec[3].second == 2) Answer++;
			if (vec[0].second == 2 && vec[1].second == 1 && vec[2].second == 2 && vec[3].second == 1) Answer++;
		}
	}

	// Step #3. Output The Answer!
	cout << Answer << endl;
	return 0;
}