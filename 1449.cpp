#include <iostream>
#include <algorithm>
using namespace std;
int N, L;
int arr[1001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> L;
	for (int x = 0; x < N; x++) {
		cin >> arr[x];
	}
	sort(arr, arr + N);
	int ans = 1;
	int st = arr[0];
	for (int x = 1; x < N; x++) {
		if (arr[x] - st + 1 > L) {
			ans++;
			st = arr[x];
		}
	}
	cout << ans;
	return 0;
}