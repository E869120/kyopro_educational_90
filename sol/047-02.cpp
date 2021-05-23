#include <string>
#include <vector>
#include <iostream>
using namespace std;
const int mod = 699999953; // large prime number
int main() {
	int N; string S, T;
	cin >> N >> S >> T;
	vector<int> seq1(N), seq3(N);
	for (int i = 0; i < N; ++i) {
		seq1[i] = (S[i] == 'R' ? 0 : (S[i] == 'G' ? 1 : 2));
		seq3[i] = (T[i] == 'R' ? 0 : (T[i] == 'G' ? 1 : 2));
	}
	int answer = 0;
	for (int i = 0; i < 3; ++i) {
		vector<int> seq2(N);
		for (int j = 0; j < N; ++j) {
			seq2[j] = (i - seq3[j] + 3) % 3;
		}
		int power3 = 1, hash1 = 0, hash2 = 0;
		for (int j = 0; j < N; ++j) {
			hash1 = (hash1 * 3 + seq1[j]) % mod;
			hash2 = (hash2 + power3 * seq2[N - j - 1]) % mod;
			if (hash1 == hash2) {
				++answer;
			}
			power3 = power3 * 3 % mod;
		}
		power3 = 1, hash1 = 0, hash2 = 0;
		for (int j = 0; j < N - 1; ++j) {
			hash1 = (hash1 + power3 * seq1[N - j - 1]) % mod;
			hash2 = (hash2 * 3 + seq2[j]) % mod;
			if (hash1 == hash2) {
				++answer;
			}
			power3 = power3 * 3 % mod;
		}
	}
	cout << answer << endl;
	return 0;
}