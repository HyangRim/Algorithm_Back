#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>
#include <cstdlib>

using namespace std;


int N;
string str[1001];

bool cmp(string a, string b) {
	if (a.size() != b.size())
		return a.size() < b.size();
	else {
		int aint = 0, bint = 0;
		for (int x = 0; x < a.size(); x++) {
			if (isdigit(a[x])) {
				aint += a[x] - '0';
			}
			if (isdigit(b[x])) {
				bint += b[x] - '0';
			}
		}
		if (aint != bint) return aint < bint;
		else return a < b;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int x = 0; x < N; x++) {
		cin >> str[x];
	}
	sort(str, str + N, cmp);
	for (int x = 0; x < N; x++) {
		cout << str[x] << "\n";
	}
	return 0;
}