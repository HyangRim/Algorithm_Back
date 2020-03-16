#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int N;
int arr[1001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;

	int M = 0;
	int pos;
	for (int x = 0; x < N; x++) {
		cin >> arr[x];

		if (arr[x] > M) {
			M = arr[x];
			pos = x;
		}
	}
	int ans = 0;
	for (int x = pos - 1; x >= 0; x--) {
		ans += M + arr[x];
	}

	for (int x = pos + 1; x < N; x++) {
		ans += M + arr[x];
	}
	cout << ans;

	return 0;
}