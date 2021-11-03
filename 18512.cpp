#include <iostream>
#include <algorithm>

using namespace std;
bool at[20001];
bool bt[20001];
int a, b;
int ax, bx;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> a >> b >> ax >> bx;
	for (int x = ax; x <= 20000; x += a) {
		at[x] = true;
	}
	for (int x = bx; x <= 20000; x += b) {
		bt[x] = true;
	}

	for (int x = 1; x <= 20000; x++) {
		if (at[x] && bt[x]) {
			cout << x;
			return 0;
		}
	}
	cout << -1;
	return 0;
}