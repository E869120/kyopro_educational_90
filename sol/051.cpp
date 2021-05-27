#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long N, K, P, Answer = 0;
long long A[100];
vector<long long> vec1[100], vec2[100];

int main() {
	// Step #1. “ü—Í
	cin >> N >> K >> P;
	for (int i = 0; i < N; i++) cin >> A[i];

	// Step #2. ”¼•ª‘S—ñ‹“
	int mid = N / 2;
	for (int i = 0; i < (1 << mid); i++) {
		long long cnt1 = 0, cnt2 = 0;
		for (int j = 0; j < mid; j++) {
			if ((i & (1 << j)) != 0) { cnt1 += A[j]; cnt2 += 1; }
		}
		vec1[cnt2].push_back(cnt1);
	}
	for (int i = 0; i < (1 << (N - mid)); i++) {
		long long cnt1 = 0, cnt2 = 0;
		for (int j = 0; j < N - mid; j++) {
			if ((i & (1 << j)) != 0) { cnt1 += A[mid + j]; cnt2 += 1; }
		}
		vec2[cnt2].push_back(cnt1);
	}
	
	// Step #3. “š‚¦‚ð‹‚ß‚é
	for (int i = 0; i <= N; i++) {
		sort(vec1[i].begin(), vec1[i].end());
		sort(vec2[i].begin(), vec2[i].end());
	}
	for (int h = 0; h <= K; h++) {
		for (int i = 0; i < (int)vec1[h].size(); i++) {
			int pos1 = lower_bound(vec2[K - h].begin(), vec2[K - h].end(), P - vec1[h][i] + 1) - vec2[K - h].begin();
			Answer += (long long)pos1;
		}
	}

	// Step #4. o—Í
	cout << Answer << endl;
	return 0;
}