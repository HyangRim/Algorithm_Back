#include <iostream>

using namespace std;

long long arr[65][10];
long long ans[65];
int N;
int main() {

	for (int x = 0; x < 10; x++) {
		arr[0][x] = 1;
	}
	for (int x = 1; x <= 64; x++) {
		unsigned long long sum = 0;
		for (int y = 0; y < 10; y++) {
			arr[x][y] = (arr[x - 1][y] + sum);
			sum += arr[x - 1][y];
		}
		ans[x] = 0;
		for (int y = 0; y < 10; y++) {
			ans[x] += arr[x][y];
		}
	}
	cin >> N;
	while (N--) {
		int tmp;
		cin >> tmp;
		if (tmp == 1) cout << 10 << "\n";
		else {
			cout << ans[tmp - 1] << "\n";
		}
	}
}