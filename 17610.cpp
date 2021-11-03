#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
using namespace std;

bool weight[2600001];
int arr[14];
bool arri[14];
int K;
int sum = 0, ans = 0;

void dfs(int n, int cnt) {
	if (n == K) {
		weight[cnt] = true;
		return;
	}
	dfs(n + 1, cnt + arr[n]);
	dfs(n + 1, cnt);
	dfs(n + 1, abs(cnt - arr[n]));
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> K;
	for (int x = 0; x < K; x++) {
		cin >> arr[x];
		sum += arr[x];
	}
	dfs(0, 0);

	for (int x = 1; x <= sum; x++) {
		if (!weight[x]) {
			ans++;
		}
	}
	cout << ans;
	return 0;
}