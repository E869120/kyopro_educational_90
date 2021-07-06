#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	// Step #1. Input
	long long K;
	cin >> K;

	// Step #2. Enumerate Divisors
	vector<long long> vec;
	for (long long i = 1; i * i <= K; i++) {
		if (K % i != 0LL) continue;
		vec.push_back(i);
		if (i != K / i) vec.push_back(K / i);
	}
	sort(vec.begin(), vec.end());

	// Step #3. Brute Force
	long long Answer = 0;
	for (int i = 0; i < vec.size(); i++) {
		for (int j = i; j < vec.size(); j++) {
			long long a = vec[i], b = vec[j], c = 0;
			if ((K / a) < b) continue;
			if (K % (a * b) != 0LL) continue;
			c = K / (vec[i] * vec[j]);
			if (b <= c) Answer += 1;
		}
	}

	// Step #4. Output
	cout << Answer << endl;
	return 0;
}