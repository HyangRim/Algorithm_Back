#include <iostream>

using namespace std;
int remax = -987654321;
int arr[4][2];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for (int x = 0; x < 4; x++) {
		for (int y = 0; y < 2; y++) {
			cin >> arr[x][y];
		}
	}
	int ans = 0;
	for (int x = 0; x < 4; x++) {
		for (int y = 0; y < 2; y++) {
			if (y == 0) {//내리기.
				if (ans - arr[x][y] < 0)
					ans = 0;
				else
					ans -= arr[x][y];
			}
			else {//타기. 
				ans += arr[x][y];
				if (remax < ans) remax = ans;
			}
		}
	}
	cout << remax;
	return 0;
}