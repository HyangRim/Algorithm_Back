#include <iostream>
#include <string>
#include <vector>

using namespace std;
int alpha[26] = {
	3,2,1,2,3,3,3,3,1,1,3,1,3,3,1,2,2,2,1,2,1,1,2,2,2,1
};
int tmp = 0;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin >> s;
	for (int x = 0; x < s.size(); x++) {
		tmp += alpha[s[x] - 'A'];
		tmp %= 10;
	}
	if (tmp % 2 == 0) {
		cout << "You're the winner?";
	}
	else {
		cout << "I'm a winner!";
	}
	return 0;
}