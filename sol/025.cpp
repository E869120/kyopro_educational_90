#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

long long N, B;
long long Answer = 0;

void dfs(int pos, int last, string str) {
	if (pos == 0) {
		long long rem = 1;
		for (int i = 0; i < str.size(); i++) rem *= (long long)(str[i] - '0');
		long long goal = rem + B;
		if (goal <= N) {
			string goal_str = to_string(goal);
			sort(goal_str.begin(), goal_str.end());
			reverse(goal_str.begin(), goal_str.end());
			if (goal_str == str) {
				Answer += 1;
			}
		}
		return;
	}

	for (int i = last; i >= 1; i--) {
		string str2 = str;
		str2 += ('0' + i);
		dfs(pos - 1, i, str2);
	}
}

int main() {
	cin >> N >> B;
	for (int i = 1; i <= 11; i++) {
		dfs(i, 9, "");
	}

	string V = to_string(B);
	bool flag = false;
	for (int i = 0; i < V.size(); i++) {
		if (V[i] == '0') flag = true;
	}
	if (flag == true && N >= B) Answer += 1;

	cout << Answer << endl;
	return 0;
}