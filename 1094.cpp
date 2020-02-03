#include <iostream>

using namespace std;

int X;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> X;
	int r = 0;
	while (X != 0) {
		if (X % 2 == 1) r++;
		X /= 2;
	}
	cout << r;



	return 0;
}