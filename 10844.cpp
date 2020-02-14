#include <iostream>

using namespace std;
int arr[101][11];
int main() {
	int N;
	cin >> N;
	for (int x = 1; x <= 9; x++) {
		arr[1][x] = 1;
	}
	for (int x = 2; x <= N; x++) {
		arr[x][0] = arr[x - 1][1];
		for (int y = 1; y <= 9; y++) {
			arr[x][y] = (arr[x - 1][y - 1] + arr[x - 1][y + 1]) % 1000000000;
		}
	}
	long long sum = 0;
	for (int x = 0; x < 10; x++) {
		sum += arr[N][x];
	}
	cout << sum % 1000000000;
	return 0;
}