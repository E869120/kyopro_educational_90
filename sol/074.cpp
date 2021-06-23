#include <iostream>
using namespace std;

long long N, Answer = 0;
string S;

int main() {
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		if (S[i] == 'b') Answer += 1LL * (1LL << i);
		if (S[i] == 'c') Answer += 2LL * (1LL << i);
	}
	cout << Answer << endl;
	return 0;
}