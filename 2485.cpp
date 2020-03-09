#include <iostream>
#include <algorithm>
using namespace std;
int arr[100001];
int art[100001];
int gcd(int a, int b) {
	return b ? gcd(b, a%b) : a;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	for (int x = 0; x < N; x++) {
		cin >> arr[x];
	}
	for (int x = 1; x < N; x++) {
		art[x] = arr[x] - arr[x - 1];
	}
	int tmp;
	int min = 987654321;
	for (int x = 1; x < N - 1; x++) {
		tmp = gcd(art[x - 1], art[x]);
		if (min > tmp) min = tmp;
	}
	int ans = 0;
	for (int x = 0; x < N; x++) {
		if (x + 1 == N) break;
		if (arr[x - 1] - arr[x] != min) {
			tmp = (arr[x+1] - arr[x]) / min -1;
			ans += tmp;
		}
	}
	cout << ans;

	return 0;
}