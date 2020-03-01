#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;

	while (N>1) {
		int temp = 2;
		while (1) {
			if (!(N%temp)) {
				N /= temp;
				cout << temp << "\n";
				break;
			}
			temp++;
		}
	}
	return 0;
}