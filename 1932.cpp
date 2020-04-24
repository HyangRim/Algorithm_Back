#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;


int arr[501][501];
int N;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int x = 0; x < N; x++) {
		for (int y = 0; y <= x; y++) {
			cin >> arr[x][y];
			arr[x][y] += max(arr[x - 1][y], arr[x - 1][y - 1]);
			
		}
	}
	int ans = 0;
	for (int x = 0; x < N; x++) {
		ans = max(ans, arr[N - 1][x]);
	}
	cout << ans;
	return 0;
}