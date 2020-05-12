#include <iostream>

using namespace std;
int arr[1001];
int dp[1001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int max = 0;
	int N;
	cin >> N;
	for (int x = 0; x < N; x++) {
		cin >> arr[x];
	}
	for (int x = 0; x < N; x++) {
		int min = 0;
		for (int y = 0; y < x; y++) {//y ~ x까지. 
			if (arr[x] > arr[y])// x가 y보다 크면
				if (min < dp[y])// 그러면서 min값보다 dp[y]값이 크면
					min = dp[y];//min에다가 dp[y]넣기
		}
		dp[x] = min + 1;// 그리고 dp[x]는 min(dp[y])해서 증가수열?하기.
		if (max < dp[x])
			max = dp[x];
	}
	cout << max;
	return 0;
}