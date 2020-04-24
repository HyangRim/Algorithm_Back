#include <iostream>
#include <vector>
using namespace std;
int arr[1001];
vector<int> dp[1001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	for (int x = 0; x < N; x++) {
		cin >> arr[x];
	}
	for (int x = 0; x < N; x++) {
		int min = 0;
		for (int y = 0; y < N; y++) {
			if (arr[x] > arr[y]) {

			}
		}
	}
	return 0;
}