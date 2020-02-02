#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int N;
int arr[501][501];
int cache[501][501];

int maxSum(int stage, int idx) {
	int &result = cache[stage][idx];
	if (result != -1)
		return result;
	if (stage == N - 1)
		return result = arr[stage][idx];
	return result = max(maxSum(stage + 1, idx), maxSum(stage + 1, idx + 1)) + arr[stage][idx];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int x = 0; x < N; x++) {
		for (int y = 0; y <= x; y++) {
			cin >> arr[x][y];
		}
	}
	memset(cache, -1, sizeof(cache));
	cout << maxSum(0, 0);
}

