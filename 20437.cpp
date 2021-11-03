#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int T;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string w;
	int k;
	cin >> T;
	vector<int> alpha[26], cent;
	while (T--) {
		cin >> w >> k;
		int wsz = w.size();
		cent.clear();
		for (int x = 0; x < 26; x++) {
			alpha[x].clear();
		}
		for (int x = 0; x < w.size(); x++) {
			alpha[w[x] - 'a'].push_back(x);
		}
		for (int x = 0; x < 26; x++) {
			if (alpha[x].size() < k) continue;
			for (int y = 0; y + k - 1 < alpha[x].size(); y++) {
				cent.push_back(alpha[x][y + k - 1] - alpha[x][y] + 1);
			}
		}
		if (!cent.size()) cout << -1 << "\n";
		else {
			sort(cent.begin(), cent.end());
			cout << cent[0] << " " << cent[cent.size() - 1] << "\n";
		}
	}
	return 0;
}