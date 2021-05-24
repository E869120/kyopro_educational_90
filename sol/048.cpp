#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long N, K, A[1 << 18], B[1 << 18];
vector<long long> vec;

int main() {
	// Step #1. “ü—Í‚È‚Ç
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> A[i] >> B[i];
		vec.push_back(B[i]);
		vec.push_back(A[i] - B[i]);
	}

	// Step #2. “š‚¦‚ğ‹‚ß‚é
	long long Answer = 0;
	sort(vec.begin(), vec.end());
	reverse(vec.begin(), vec.end());
	for (int i = 0; i < K; i++) Answer += vec[i];

	// Step #3. o—Í
	cout << Answer << endl;
	return 0;
}