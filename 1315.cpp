#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;



vector<pair<pair<int, int>, int>> v1;
int N;
int dp[1001][1001];
int ans = -987654321;
void solve(int str, int it) {
	int &ret = dp[str][it];//현재 스텟으로 깰 수 있는 퀘스트개수. 
	if (ret != -1) return;

	ret = 0;
	int gp = 2;

	for (int x = 0; x < N; x++) {
		pair<int, int> next = v1[x].first;
		int p = v1[x].second;//스텟포인트.

		if (next.first <= str || next.second <= it) {
			gp += p;
			ret++;
		}
	}
	ans = max(ans, ret);

	gp -= str;
	gp -= it;

	for (int x = str; x <= min(1000, str + gp); x++)
		solve(x, min(1000, str - x + gp + it));
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	cin >> N;
	int s, i, p;
	for (int x = 0; x < N; x++) {
		cin >> s >> i >> p;
		v1.push_back({ {s,i},p });
	}
	memset(dp, -1, sizeof(dp));

	solve(1, 1);//현재 str, int
	cout << ans;
	return 0;
}