#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

struct Point {
	double px, py;
};

Point operator-(const Point& a1, const Point& a2) {
	return Point{ a1.px - a2.px, a1.py - a2.py };
}

double getangle(Point G) {
	// 点 G の偏角を求める
	if (G.py >= 0.0) {
		double I = G.px / sqrt(G.px * G.px + G.py * G.py);
		double kaku = acos(I) * 180.0 / 3.14159265358979;
		return kaku;
	}
	else {
		double I = G.px / sqrt(G.px * G.px + G.py * G.py);
		double kaku = acos(I) * 180.0 / 3.14159265358979;
		return 360.0 - kaku;
	}
}

double getangle2(double I1, double I2) {
	// [偏角 I1] - [原点] - [偏角 I2] のなす角度を求める
	// 例えば I1 = 240°、I2 = 30°のとき、求める角度は 150°
	double res = abs(I1 - I2);
	if (res >= 180.0) return 360.0 - res;
	return res;
}

int N;
Point G[2009];

double solve(int pos) {
	// 最初に偏角の昇順にソートする
	vector<double> vec;
	for (int i = 1; i <= N; i++) {
		if (i == pos) continue;
		Point SA = G[i] - G[pos];
		double angle = getangle(SA);
		vec.push_back(angle);
	}
	sort(vec.begin(), vec.end());

	// 点 A を全探索して、最も偏角の大きくなる点 C を二分探索（std::lower_bound）で求める
	double ret = 0.0;
	for (int i = 0; i < vec.size(); i++) {
		double target = vec[i] + 180.0;
		if (target >= 360.0) target -= 360.0;
		int pos1 = lower_bound(vec.begin(), vec.end(), target) - vec.begin();

		// 点 C の候補は高々 2 つに絞れる
		int CandIdx1 = pos1 % vec.size();
		int CandIdx2 = (pos1 + vec.size() - 1) % vec.size();
		double Candidate1 = getangle2(vec[i], vec[CandIdx1]);
		double Candidate2 = getangle2(vec[i], vec[CandIdx2]);
		ret = max({ ret, Candidate1, Candidate2 });
	}
	return ret;
}

// O(N^3) のアルゴリズム（点 A, B, C を全探索）
double solve_Slow() {
	double Answer = 0.0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				if (i == j || i == k || j == k) continue;
				double I1 = getangle(G[i] - G[j]);
				double I2 = getangle(G[k] - G[j]);
				Answer = max(Answer, getangle2(I1, I2));
			}
		}
	}
	return Answer;
}

// O(N^2 log N) のアルゴリズム
double solve_Fast() {
	// 点 B を全探索
	double Answer = 0.0;
	for (int i = 1; i <= N; i++) {
		double ret = solve(i);
		Answer = max(Answer, ret);
	}
	return Answer;
}

int main() {
	// Step #1. 入力
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> G[i].px >> G[i].py;
	}

	// Step #2. 出力
	double FinalAns = solve_Fast();
	printf("%.12lf\n", FinalAns);
	return 0;
}