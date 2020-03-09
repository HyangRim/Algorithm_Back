#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr[100001];
int dp[100001];
int N;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int x = 1; x <= N; x++) {
		cin >> arr[x];
	}
	for (int x = 1; x <= N; x++) {
		if (dp[x - 1] + arr[x] > arr[x])
			dp[x] = dp[x - 1] + arr[x];
		else
			dp[x] = arr[x];
	}
	int max = dp[1];
	for (int x = 2; x <= N; x++)
		if (max < dp[x])
			max = dp[x];
	cout << max;
	return 0;
}