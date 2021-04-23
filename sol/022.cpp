#include <iostream>
using namespace std;

long long gcd(long long a, long long b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

long long A, B, C;

int main() {
	cin >> A >> B >> C;
	long long S = gcd(A, gcd(B, C));
	cout << (A / S - 1LL) + (B / S - 1LL) + (C / S - 1LL) << endl;
	return 0;
}