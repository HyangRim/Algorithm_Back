#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	long long a, b;
	long long ans = 0;
	cin >> a >> b;
	if (a <= 2) a = 3;
	if (a % 2) a++;
	if (b % 2) b--;
	a /= 2;
	b /= 2;

	if (a > b) cout << 0;
	else cout << (b*(b + 1) - a * (a - 1));
	return 0;
}