#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int T;
int arr[2][100001];
int ans[2][100001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		for (int x = 0; x <= 1; x++) {
			for (int y = 1; y <= N; y++) {
				cin >> arr[x][y];
			}
		}
		
		ans[0][1] = arr[0][1];
		ans[1][1] = arr[1][1];

		for (int x = 2; x <= N; x++) {
			ans[0][x] = max(ans[1][x - 1], ans[1][x - 2]) + arr[0][x];
			ans[1][x] = max(ans[0][x - 1], ans[0][x - 2]) + arr[1][x];
		}
		cout << max(ans[0][N], ans[1][N]) << "\n";
	}
	return 0;
}