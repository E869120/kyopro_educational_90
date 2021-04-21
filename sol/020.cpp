#include <iostream>
using namespace std;

long long A, B, C;
long long E = 1;

int main() {
	cin >> A >> B >> C;
	for (int i = 1; i <= B; i++) E *= C;
	if (A < E) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}