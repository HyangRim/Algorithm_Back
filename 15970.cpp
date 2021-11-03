#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

struct node {
	int pt, color;
};
int T;
int ans = 0;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vector<node> v1;
	cin >> T;
	while (T--) {
		int a, b;
		cin >> a >> b;
		v1.push_back({ a,b });
	}
	for (int x = 0; x < v1.size(); x++) {
		int maxlen = 987654321;
		for (int y = 0; y < v1.size(); y++) {
			if (x == y) continue;
			if (v1[x].color == v1[y].color) maxlen = min(maxlen, abs(v1[x].pt - v1[y].pt));
		}
		ans += maxlen;
	}
	cout << ans;
	return 0;
}