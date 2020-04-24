#include <iostream>

using namespace std;
int N, M;
int i, j, x, y;
int T;
int arr[301][301];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= M; y++) {
			cin >> arr[x][y];
		}
	}
	cin >> T;
	while (T--) {
		int ans = 0;
		cin >> i >> j >> x >> y;
		int temp = (x*y) - (i*j);
		int *cmp = &arr[i][j];
		while (temp--) {
			ans += *(cmp);
			cmp++;
			cout << *cmp << "\n";
		}
		cout << ans << "\n";
	}
	return 0;
}