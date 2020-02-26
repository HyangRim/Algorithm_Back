#include <iostream>
#include <string>
#include <vector>
using namespace std;
int alpha[26];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string str;

	cin >> str;
	for (int x = 0; x < str.size(); x++) {
		alpha[str[x] - 'A']++;
	}

	vector<pair<char, int>> v1;
	vector<char> middle;

	bool flag = false;

	for (int x = 0; x < 26; x++) {
		if (alpha[x] % 2 && flag) {
			cout << "I'm Sorry Hansoo\n";
			return 0;
		}
		else if (alpha[x] % 2 && !flag) {
			v1.push_back({ x + 'A',alpha[x] - 1 });
			middle.push_back(x + 'A');
			flag = true;
		}
		else {
			v1.push_back({ x + 'A', alpha[x] });
		}
	}

	string result;
	for (int x = 0; x < v1.size(); x++) {
		for (int y = 0; y < (v1[x].second / 2); y++)
			result += v1[x].first;
	}

	for (int x = 0; x < result.size(); x++)
		cout << result[x];
	if (middle.size())
		cout << middle[0];
	for (int x = result.size() - 1; x >= 0; x--) {
		cout << result[x];
	}
	return 0;
}