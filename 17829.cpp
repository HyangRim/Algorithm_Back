#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int arr[1025][1025];
int N;

int pulling(int y, int x) {
	vector<int> v1;

	for (int i = y; i < y + 2; i++) {
		for (int j = x; j < x + 2; j++) {
			v1.push_back(arr[i][j]);
		}
	}
	sort(v1.begin(), v1.end());
	return v1[2];
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x) {
			cin >> arr[y][x];
		}
	}

	while (N>1) {
		for (int y = 0; y < N; y+= 2) {
			for (int x = 0; x < N; x+=2) {
				arr[y / 2][x / 2] = pulling(y, x);
			}
		}
		N /= 2;
	}
	cout << arr[0][0];
	return 0;
}