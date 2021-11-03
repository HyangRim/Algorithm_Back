#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;
string t, tc;
int ans = -1;
bool visited[10];
int B;
void dfs(int i) {
	if (i == t.length()) {
		if (stoi(tc) <= B) {
			ans = max(ans, stoi(tc));
		}
		return;
	}

	for (int x = 0; x < t.size(); x++) {
		if (!visited[x]) {
			if (i != 0 || t[x] != '0') {
				tc.push_back(t[x]);
				visited[x] = true;
				dfs(i + 1);
				visited[x] = false;
				tc.pop_back();
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> t >> B;
	dfs(0);
	cout << ans;
	return 0;
}