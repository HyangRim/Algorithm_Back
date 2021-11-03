#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;
int arr[26];
int T;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	cin.ignore();
	while (T--) {
		int ans = 0;
		char ans_index = 0;
		memset(arr, 0, sizeof(arr));
		string s;
		getline(cin, s);
		for (int x = 0; x < s.size(); x++) {
			if (s[x] != ' ') {
				arr[s[x] - 'a']++;
			}
		}

		for (int x = 0; x < 26; x++) {
			if (ans < arr[x]) {
				ans = arr[x];
				ans_index = x;
			}
		}
		int ct = 0;
		for (int x = 0; x < 26; x++) {
			if (ans == arr[x]) ct++;
		}
		if (ct > 1) {
			cout << "?\n";
		}
		else {
			cout << (char)(ans_index + 'a') << "\n";
		}
	}
	return 0;
}