#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;
char str[1000001];
char tmp[1000001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> str;
	cin >> tmp;
	char* ptr = strstr(str, tmp);
	if (ptr == NULL) {
		cout << 0;
	}
	else {
		cout << 1;
	}
	return 0;
}