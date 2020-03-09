#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dp[300001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int N, Q;
	cin >> N >> Q;
	vector<int>v1(N+1);
	for (int x = 1; x <= N; x++) {
		cin >> v1[x];
	}
	sort(v1.begin(), v1.end());
	for (int x = 1; x <= N; x++) {
		dp[x] = dp[x - 1] + v1[x];
	}
	for (int x = 0; x < Q; x++) {
		int L, R;
		cin >> L >> R;
		cout << dp[R] - dp[L-1] << "\n";
	}
	
	return 0;

}