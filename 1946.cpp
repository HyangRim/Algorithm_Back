#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int T, N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while (T--) {
		cin >> N;
		vector<pair<int, int>> v1(N);
		for (int x = 0; x < N; x++) {
			cin >> v1[x].first >> v1[x].second;
		}
		sort(v1.begin(), v1.end());
		int result = 1;
		int ivR = v1[0].second;
		for (int x = 1; x < N; x++) {
			if (v1[x].second < ivR) {
				result++;
				ivR = v1[x].second;
			}
		}
		cout << result << "\n";
	}


	return 0;
}