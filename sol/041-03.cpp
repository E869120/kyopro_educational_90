#include <iostream>
#include <vector>
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

bool operator<(const Point& a1, const Point& a2) {
	if (a1.px < a2.px) return true;
	if (a1.px > a2.px) return false;
	if (a1.py < a2.py) return true;
	return false;
}

// 点 p1 と p2 の外積を求める
long long crs(Point p1, Point p2) {
	return p1.px * p2.py - p1.py * p2.px;
}

long long gcd(long long a, long long b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

long long N;
Point G[100009];

int main() {
	// Step #1. 入力
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> G[i].px >> G[i].py;
	sort(G + 1, G + N + 1);

	// Step #2. 凸包を求める
	vector<Point> G1, G2, Totsuhou;
	G1.push_back(G[1]); G2.push_back(G[1]);
	G1.push_back(G[2]); G2.push_back(G[2]);
	for (int i = 3; i <= N; i++) {
		while (G1.size() >= 2 && crs(G1[G1.size() - 1] - G1[G1.size() - 2], G[i] - G1[G1.size() - 1]) <= 0) G1.pop_back();
		while (G2.size() >= 2 && crs(G2[G2.size() - 1] - G2[G2.size() - 2], G[i] - G2[G2.size() - 1]) >= 0) G2.pop_back();
		G1.push_back(G[i]);
		G2.push_back(G[i]);
	}
	for (int i = 0; i < G1.size(); i++) Totsuhou.push_back(G1[i]);
	for (int i = (int)G2.size() - 2; i >= 1; i--) Totsuhou.push_back(G2[i]);

	// Step #3. 辺上の格子点の数を求める
	long long EdgePoint = Totsuhou.size();
	for (int i = 0; i < Totsuhou.size(); i++) {
		long long ax = Totsuhou[(i + 0) % Totsuhou.size()].px, ay = Totsuhou[(i + 0) % Totsuhou.size()].py;
		long long bx = Totsuhou[(i + 1) % Totsuhou.size()].px, by = Totsuhou[(i + 1) % Totsuhou.size()].py;
		long long vx = abs(bx - ax);
		long long vy = abs(by - ay);
		long long r = gcd(vx, vy);
		EdgePoint += (r - 1LL);
	}

	// Step #4. 多角形の面積（を 2 倍した値）を求める
	long long Area = 0;
	for (int i = 0; i < Totsuhou.size(); i++) {
		long long ax = Totsuhou[(i + 0) % Totsuhou.size()].px, ay = Totsuhou[(i + 0) % Totsuhou.size()].py;
		long long bx = Totsuhou[(i + 1) % Totsuhou.size()].px, by = Totsuhou[(i + 1) % Totsuhou.size()].py;
		Area += (bx - ax) * (by + ay);
	}
	Area = abs(Area);

	// Step #5. 答えを求める
	long long Answer = Area + EdgePoint + 2LL;
	cout << (Answer / 2LL) - N << endl;
	return 0;
}