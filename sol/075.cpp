#include <iostream>
#include <vector>
using namespace std;

vector<long long> prime_factors(long long N) {
	long long rem = N;
	vector<long long> p;
	for (long long i = 2; i * i <= N; i++) {
		while (rem % i == 0) {
			rem /= i;
			p.push_back(i);
		}
	}
	if (rem != 1LL) p.push_back(rem);
	return p;
}

int main() {
	// Step #1. Input
	long long N;
	cin >> N;
	
	// Step #2. Get Answer
	int Answer = 0;
	vector<long long> vec = prime_factors(N);
	for (int i = 0; i <= 20; i++) {
		if ((1 << i) >= (int)vec.size()) { Answer = i; break; }
	}
	cout << Answer << endl;
	return 0;
}