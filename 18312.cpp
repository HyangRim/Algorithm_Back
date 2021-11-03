#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
int N, K;
int ans = 0;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K;
	int stoptime = N * 3600 + 3599;
	string kk = to_string(K);
	for (int x = 0; x <= stoptime; x++) {
		string tmp;
		int hour = x / 3600;
		int mint = x % 3600 / 60;
		int second = x % 60;

		if (hour < 10) tmp += '0';
		if (mint < 10) tmp += '0';
		if (second < 10)tmp += '0';

		tmp += to_string(hour);
		tmp += to_string(mint);
		tmp += to_string(second);

		if (tmp.find(kk) != -1) {
			ans++;
		}
	}
	cout << ans;
	return 0;
}