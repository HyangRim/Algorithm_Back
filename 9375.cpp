#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int T,N;
int ans;
string tmp, key;

vector<pair<string, int>> v1;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		map<string, int> m1;
		ans = 1;
		cin >> N;

		for (int x = 0; x < N; x++) {
			cin >> tmp >> key;
			if (m1.find(key) == m1.end()) m1[key] = 1;
			else m1[key]++;
		}

		for (auto iter : m1) ans *= (iter.second + 1);

		cout << ans - 1 << "\n";

	}
	return 0;
}