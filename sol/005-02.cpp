#include <iostream>
using namespace std;

const long long mod = 1000000007;
const int MAX_N = 33;

struct Matrix {
	int sz; // sz ~ sz s—ñ
	long long x[MAX_N][MAX_N];
};

Matrix multiply(Matrix A, Matrix B) {
	// A ~ B ‚ğ‹‚ß‚é
	Matrix C;
	C.sz = A.sz;
	for (int i = 0; i < C.sz; i++) {
		for (int j = 0; j < C.sz; j++) C.x[i][j] = 0;
	}
	for (int i = 0; i < A.sz; i++) {
		for (int j = 0; j < A.sz; j++) {
			for (int k = 0; k < A.sz; k++) {
				C.x[i][k] += A.x[i][j] * B.x[j][k];
				C.x[i][k] %= mod;
			}
		}
	}
	return C;
}

Matrix powers(Matrix A, long long T) {
	// A ‚Ì T æ‚ğ‹‚ß‚é
	Matrix E[64], F;
	E[0] = A;
	for (int i = 1; i < 62; i++) {
		E[i] = multiply(E[i - 1], E[i - 1]);
	}

	F.sz = E[0].sz;
	for (int i = 0; i < F.sz; i++) {
		for (int j = 0; j < F.sz; j++) {
			if (i == j) F.x[i][j] = 1;
			if (i != j) F.x[i][j] = 0;
		}
	}

	for (int i = 62; i >= 0; i--) {
		if ((T & (1LL << i)) != 0LL) {
			F = multiply(F, E[i]);
		}
	}
	return F;
}

// “ü—Í
long long N, B, K;
long long C[11];

int main() {
	// Step #1. “ü—Í
	cin >> N >> B >> K;
	for (int i = 1; i <= K; i++) cin >> C[i];

	// Step #2. s—ñ A ‚ğ‹‚ß‚é
	Matrix A; A.sz = B;
	for (int i = 0; i < B; i++) {
		for (int j = 0; j < B; j++) A.x[i][j] = 0;
	}
	for (int i = 0; i < B; i++) {
		for (int j = 1; j <= K; j++) {
			int nex = (i * 10 + C[j]) % B;
			A.x[i][nex] += 1;
		}
	}

	// Step #3. s—ñ—İæ‚ğ‚·‚é
	Matrix Z = powers(A, N);

	// Step #4. “š‚¦‚ğ‹‚ß‚é
	long long Answer = Z.x[0][0];
	cout << Answer << endl;
	return 0;
}