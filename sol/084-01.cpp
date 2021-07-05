#include <iostream>
#include <string>
#include <vector>
using namespace std;

long long N;
string S;
vector<pair<char, long long>> vec;

int main() {
	cin >> N >> S;

	long long cnt = 0;
	for (int i = 0; i < S.size(); i++) {
		cnt++;
		if (i == (int)S.size() - 1 || S[i] != S[i + 1]) {
			vec.push_back(make_pair(S[i], cnt));
			cnt = 0;
		}
	}

	long long ret = 0;
	for (int i = 0; i < vec.size(); i++) {
		ret += 1LL * vec[i].second * (vec[i].second + 1LL) / 2LL;
	}
	cout << N * (N + 1) / 2LL - ret << endl;
	return 0;
}