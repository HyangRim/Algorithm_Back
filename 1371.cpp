#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
int alphabet[26];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s;
	while (cin >> s) {
		for (int x = 0; x < s.length(); x++) {
			if (s[x] >= 'a' && s[x] <= 'z')
				alphabet[s[x] - 'a']++;
		}
		s.clear();
	}

	int temp = alphabet[0];

	for (int x = 1; x < 26; x++) {
		temp = max(temp, alphabet[x]);
	}

	for (int x = 0; x < 26; x++) {
		if (alphabet[x] == temp)	cout << (char)(x + 'a');
	}
	cout << "\n";
	return 0;
}