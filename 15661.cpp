#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int N;
int arr[21][21];
int ans = 987654321;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> arr[y][x];
		}
	}
	for (int x = 1; x < N - 1; x++) {
		vector<int> v1;
		for (int y = 0; y < x; y++) {
			v1.push_back(0);
		}
		for (int y = 0; y < N - x; y++) {
			v1.push_back(1);
		}
		//여기까지 v1을 통해서 팀배정. [1] = 1이면 2번째 사람이 0팀으로 감. 
		do {
			int asum = 0, bsum = 0;
			vector<int> a, b;
			for (int x = 0; x < N; x++) {
				if (v1[x] == 0)a.push_back(x);
				else b.push_back(x);
			}
			for (int x = 0; x < a.size() - 1; x++) {
				for (int y = x + 1; y < a.size(); y++) {
					asum += (arr[a[x]][a[y]] + arr[a[y]][a[x]]);
				}
			}
			for (int x = 0; x < b.size() - 1; x++) {
				for (int y = x + 1; y < b.size(); y++) {
					bsum += (arr[b[x]][b[y]] + arr[b[y]][b[x]]);
				}
			}
			ans = min(ans, abs(asum - bsum));
		} while (next_permutation(v1.begin(), v1.end()));
	}

	cout << ans;
	return 0;
}