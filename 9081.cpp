#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
int T;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while (T--) {
		string s, ans;
		int chk = 0;
		cin >> s;
		do {
			ans = s;
			chk++;
			if (chk == 2)break;
		} while (next_permutation(s.begin(), s.end()));
		cout << ans << "\n";
	}
	return 0;
}