#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;
int M, N;
int arr[8];
int ans[8];
bool visited[8];


void dfs(int cnt, int prv) {
	if (cnt == M) {
		for (int x = 0; x < M;  x++) {
			cout << ans[x] << " ";
		}
		cout << "\n";
		return;
	}

	int prev = -1;

	for (int x = 0; x < N; x++) {
		if (prev != arr[x] && prv <= arr[x]) {
			ans[cnt] = arr[x];
			prev = arr[x];
			prv = arr[x];
			dfs(cnt + 1, ans[cnt]);
		}
	}
}
int main() {
	cin >> N >> M;
	for (int x = 0; x < N; x++) {
		cin >> arr[x];
	}
	sort(arr, arr + N);
	dfs(0, -1);
	return 0;
}