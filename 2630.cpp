#include <iostream>

using namespace std;

int arr[129][129];

int white, blue;
void solve(int N, int x, int y) {
	int val = arr[x][y];

	for (int a = x; a < x + N; a++) {
		for (int b = y; b < y + N; b++) {
			if (val != arr[a][b]) {
				val = -1;
				break;
			}
		}
		if (val == -1) break;
	}

	if (val == 0) {
		white++;
	}
	else if (val == 1) {
		blue++;
	}
	else {
		solve(N / 2, x, y);
		solve(N / 2, N / 2 + x, y);
		solve(N / 2, x, N / 2 + y);
		solve(N / 2, N / 2 + x, N / 2 + y);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			cin >> arr[x][y];
		}
	}
	solve(N, 0, 0);
	cout << white << "\n" << blue;
	return 0;
}