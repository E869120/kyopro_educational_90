#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Input
long long N, M;
long long L[1 << 18], R[1 << 18];

// Kazoeage
long long V1[1 << 18], V2[1 << 18], V3[1 << 18];
long long cnt[1 << 18];

int main() {
	// Step #1. Input
	cin >> N >> M;
	for (int i = 1; i <= M; i++) cin >> L[i] >> R[i];

	// Step #2. Get Answer1
	long long Answer1 = 0;
	for (int i = 1; i <= M; i++) V3[L[i]] += 1;
	for (int i = 1; i <= M; i++) V3[R[i]] += 1;
	for (int i = 1; i <= N; i++) Answer1 += V3[i] * (V3[i] - 1LL) / 2LL;

	// Step #3. Get Answer2
	long long Answer2 = 0;
	for (int i = 1; i <= M; i++) V1[R[i]] += 1;
	for (int i = 1; i <= M; i++) V2[L[i] - 1] += 1;
	for (int i = 1; i <= N; i++) V1[i] += V1[i - 1];
	for (int i = 1; i <= N; i++) Answer2 += V1[i] * V2[i];

	// Step #4. Sorting
	vector<pair<long long, long long>> vec;
	for (int i = 1; i <= M; i++) vec.push_back(make_pair(R[i], L[i]));
	sort(vec.begin(), vec.end());

	// Step #5. Get Answer3
	long long Answer3 = 0;
	for (int i = 0; i < vec.size(); i++) {
		long long cl = vec[i].second, cr = vec[i].first;
		long long ret = 0;
		for (int j = cl + 1; j <= cr; j++) ret += cnt[j];
		Answer3 += ret;
		cnt[cl] += 1;
	}

	// Step #6. Output The Answer!
	long long Total = M * (M - 1) / 2LL;
	long long SumAns = Answer1 + Answer2 + Answer3;
	cout << Total - SumAns << endl;
	return 0;
}