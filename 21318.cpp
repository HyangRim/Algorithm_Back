#include <iostream>

using namespace std;

int N;
int arr[100001], dp[100001];
int a = 0;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int x = 1; x <= N; x++) {
		cin >> arr[x];
	}

	for (int x = 1; x <= N; x++) {
		if (arr[x] > arr[x + 1])a++;
		dp[x] = a;
	}
	cin >> N;
	int X, Y;
	for (int x = 0; x < N; x++) {
		cin >> X >> Y;
		cout << dp[Y-1] - dp[X-1] << "\n";
	}
}