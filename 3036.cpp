#include <iostream>

using namespace std;
int arr[101];
int N;

int gcd(int x, int y) {
	return y ? gcd(y, x%y) : x;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int x = 0; x < N; x++) {
		cin >> arr[x];
	}
	for (int x = 1; x < N; x++) {
		int gcdNum = gcd(arr[0], arr[x]);
		cout << arr[0] / gcdNum << "/" << arr[x] / gcdNum << "\n";
	}
	return 0;
}