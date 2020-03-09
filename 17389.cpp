#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int size = 0;
	int bonus = 0;
	int Point = 0;
	string str;
	cin >> size;
	cin >> str;
	for (int x = 0; x < size; x++) {
		if (str[x] == 'X') {
			bonus = 0;
		}
		else if (str[x] == 'O') {
			Point += ((x + 1) + bonus);
			bonus++;
		}
	}
	cout << Point;
	return 0;
}