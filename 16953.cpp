#include <iostream>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;
int A, B;
int ans = 987654321;
void dfs(int cnt, long long a) {
	if (a > B)return;
	if (a == B) ans = min(ans, cnt);
	dfs(cnt + 1, a * 2);
	string tmp = to_string(a);
	tmp += '1';
	dfs(cnt + 1, stoi(tmp));
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> A >> B;
	dfs(1, A);

	if (ans == 987654321) cout << -1;
	else cout << ans;
	return 0;
}