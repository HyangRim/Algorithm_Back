#include <iostream>

using namespace std;


long long mul(int a, int b, int c) {
	if (b == 1)
		return a;
	if (b % 2 == 1)
		return 1LL * mul(a, b - 1, c)*a%c;
	int ret = mul(a, b / 2, c);
	return 1LL * ret*ret%c;
}
int main() {
	int A, B, C;

	cin >> A >> B >> C;
	cout << mul(A,B,C);
	return 0;
}