#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

using namespace std;

int N;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	map<string, int> m1;
	cin >> N;
	while(N--) {
		string s, s2;
		cin >> s;
		int idx = s.find(".");
		for (int i = idx + 1; i < s.size(); i++) {
			s2 += s[i];
		}
		m1[s2]++;
	}
	for (auto iter = m1.begin(); iter != m1.end(); iter++) {
		cout << iter->first << " " << iter->second << "\n";
	}
	return 0;
}