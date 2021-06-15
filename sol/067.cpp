#include <string>
#include <iostream>
using namespace std;
long long base8_to_long(string N) {
	long long res = 0;
	for (int i = 0; i < N.size(); ++i) {
		res = res * 8 + int(N[i] - '0');
	}
	return res;
}
string long_to_base9(long long N) {
	if (N == 0) {
		return "0";
	}
	string res;
	while (N > 0) {
		res = char(N % 9 + '0') + res;
		N /= 9;
	}
	return res;
}
int main() {
	string N; int K;
	cin >> N >> K;
	for (int i = 0; i < K; ++i) {
		N = long_to_base9(base8_to_long(N));
		for (int j = 0; j < N.size(); ++j) {
			if (N[j] == '8') {
				N[j] = '5';
			}
		}
	}
	cout << N << endl;
	return 0;
}