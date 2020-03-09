#include <iostream>
#include <algorithm>

using namespace std;


int N, M;
int sum;
int ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	int feel;
	for (int x = 0; x < N; x++) {
		cin >> feel;
		M -= (feel + 1);
	}

	if (M <= 0) {
		cout << 0;
		return 0;
	}
	int Q = M / (N + 1);
	int R = M % (N + 1);
	for (int x = 0, y = 0; x < N + 1; x++, y++) {
		int val = (y < R) ? Q + 1 : Q;
		ans += val * (val + 1) * (val * 2 + 1) / 6;
	}
	cout << ans;
	return 0;
}