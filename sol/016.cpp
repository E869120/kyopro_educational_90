#include <iostream>
#include <algorithm>
using namespace std;

long long N;
long long A, B, C;

int main() {
	cin >> N;
	cin >> A >> B >> C;

	long long Answer = (1LL << 30);
	for (int i = 0; i <= 9999; i++) {
		for (int j = 0; j <= 9999 - i; j++) {
			long long V = N - 1LL * i * A - 1LL * j * B;
			long long R = 1LL * i + 1LL * j + V / C;
			if (V% C != 0LL || V < 0 || R > 9999LL) continue;
			Answer = min(Answer, R);
		}
	}
	cout << Answer << endl;
	return 0;
}