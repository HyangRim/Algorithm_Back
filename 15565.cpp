#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
using namespace std;
int N, K;
int arr[1000010];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> K;
	for (int x = 1; x <= N; x++) {
		cin >> arr[x];
	}
	int left = 1;
	int right = 1;
	int lion = 0;
	int ans = 987654321;

	while (left <= right && right <= N + 1) {
		if (lion < K) {
			if (arr[right] == 1) {
				lion++;
				right++;
			}
			else {
				right++;
			}
		}
		else if (lion > K) {
			if (arr[left] == 1) {
				lion--;
				left++;
			}
			else {
				left++;
			}
		}
		else if (lion == K) {
			if (ans > right - left) {
				ans = right - left;
			}
			if (arr[left] == 1) {
				lion--;
				left++;
			}
			else {
				left++;
			}
		}
	}
	if (ans == 987654321) {
		cout << -1;
	}
	else {
		cout << ans;
	}
	return 0;
}