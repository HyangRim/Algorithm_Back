#include <iostream>

using namespace std;
int arr[3];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int tag = 0;
	int max = 0;
	for (int x = 0; x < 3; x++) {
		cin >> arr[x];
		max += arr[x];
	}
	if (max >= 100) {
		cout << "OK";
		return 0;
	}
	else {
		for (int x = 0; x < 3; x++) {
			if (max > arr[x]) {
				tag = x;
				max = arr[x];
			}
		}
	}
	if (tag == 0) {
		cout << "Soongsil";
	}
	else if (tag == 1) {
		cout << "Korea";
	}
	else if (tag == 2) {
		cout << "Hanyang";
	}

	return 0;
}