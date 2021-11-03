#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

string S, E, Q;
int S1, E1, Q1;
int timetoint(string s) {
	string a;
	int inttime = 0;

	a += s[0];
	a += s[1];
	inttime = stoi(a) * 60;
	a.clear();
	a += s[3];
	a += s[4];
	inttime += stoi(a);

	return inttime;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> S >> E >> Q;
	S1 = timetoint(S);
	E1 = timetoint(E);
	Q1 = timetoint(Q);
	map<string, int> m1;
	while (1) {
		string t, nick;
		cin >> t >> nick;
		if (cin.eof() == true) break;

		int time = timetoint(t);

		if (time <= S1 && m1[nick] == 0) {
			m1[nick]++;
		}
		else if (E1 <= time && time <= Q1 && m1[nick] == 1) {
			m1[nick]++;
		}
	}
	int ans = 0;
	for (auto iter = m1.begin(); iter != m1.end(); iter++) {
		if (iter->second >= 2) {
			//cout << iter->first << "\n";
			ans++;
		}
	}
	cout << ans;
	return 0;
}