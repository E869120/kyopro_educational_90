#include <iostream>
#include <vector>
using namespace std;

long long N, K;
long long A[19];

long long count_inversions(vector<long long> vec) {
	long long cnt = 0;
	for (int i = 0; i < vec.size(); i++) {
		for (int j = i + 1; j < vec.size(); j++) {
			if (vec[i] > vec[j]) cnt++;
		}
	}
	return cnt;
}

int main() {
	// Step #1. Input
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> A[i];
	
	// Step #2. Brute Force
	long long Answer = 0;
	for (int i = 0; i < (1 << (N - 1)); i++) {
		vector<long long> vec; bool flag = true;
		for (int j = 0; j < N; j++) {
			vec.push_back(A[j]);
			if (j == N - 1 || ((i & (1 << j)) != 0)) {
				long long val = count_inversions(vec);
				if (val > K) flag = false;
				vec.clear();
			}
		}
		if (flag == true) Answer += 1;
	}

	// Step #3. Output
	cout << Answer << endl;
	return 0;
}