#include <iostream>
#include <algorithm>
using namespace std;

struct Point {
	long long px, py;
};

Point operator+(const Point& a1, const Point& a2) {
	return Point{ a1.px + a2.px, a1.py + a2.py };
}

Point operator-(const Point& a1, const Point& a2) {
	return Point{ a1.px - a2.px, a1.py - a2.py };
}

// 点 p1 と p2 の外積を求める
long long crs(Point p1, Point p2) {
	return p1.px * p2.py - p1.py * p2.px;
}

// 点 p1, p2, p3 が時計回りか反時計回りか
int ccw(Point p1, Point p2, Point p3) {
	Point va = p2 - p1;
	Point vb = p3 - p1;
	if (crs(va, vb) > 0) return 1;
	if (crs(va, vb) < 0) return -1;
	return 0;
}

long long gcd(long long a, long long b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

long long N, Answer = 0;
Point G[10];

int main() {
	// Step #1. 入力
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> G[i].px >> G[i].py;

	// Step #2. コーナーケース
	if (crs(G[2] - G[1], G[3] - G[1]) == 0) {
		long long cl = min({ G[1].px, G[2].px, G[3].px });
		long long cr = max({ G[1].px, G[2].px, G[3].px });
		long long dl = min({ G[1].py, G[2].py, G[3].py });
		long long dr = max({ G[1].py, G[2].py, G[3].py });
		long long ret = gcd(cr - cl, dr - dl);
		cout << ret - 2 << endl;
		return 0;
	}

	// Step #3. 答えの計算
	for (int i = 0; i <= 1000; i++) {
		for (int j = 0; j <= 1000; j++) {
			Point H = Point{ i, j };
			int cnt = 0;
			if (ccw(G[1], H, G[2]) == ccw(G[1], H, G[3])) cnt++;
			if (ccw(G[2], H, G[3]) == ccw(G[2], H, G[1])) cnt++;
			if (ccw(G[3], H, G[1]) == ccw(G[3], H, G[2])) cnt++;
			if (cnt == 0) Answer += 1;
		}
	}

	// Step #4. 出力
	cout << Answer << endl;
	return 0;
}