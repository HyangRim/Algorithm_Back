#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int p, w;
string str;

int num[26] = {
	2,2,2,
	3,3,3,
	4,4,4,
	5,5,5,
	6,6,6,
	7,7,7,7,
	8,8,8,
	9,9,9,9
};

int Count[26] = {
	1,2,3,
	1,2,3,
	1,2,3,
	1,2,3,
	1,2,3,
	1,2,3,4,
	1,2,3,
	1,2,3,4
};


int main() {


	cin >> p >> w;
	cin.ignore();
	getline(cin, str);
	int ans = 0;
	//cout << str;
	for (int x = 0; x < str.size(); x++) {
		if (x > 0 && isalpha(str[x]) && isalpha(str[x - 1]))
			if (num[str[x] - 'A'] == num[str[x - 1] - 'A'])
				ans += w;
		if (isalpha(str[x]))ans += Count[str[x] - 'A'] * p;
		else ans += p;
	}
	cout << ans;
	return 0;
}