#include <iostream>

using namespace std;
unsigned long long arr[101];
int main() {
	arr[0] = 0;
	arr[1] = 1;
	arr[2] = 1;
	arr[3] = 1;
	arr[4] = 2;
	arr[5] = 2;
	arr[6] = 3;
	arr[7] = 4;
	arr[8] = 5;
	arr[9] = 7;
	arr[10] = 9;
	for (int x = 11; x <= 100; x++) {
		arr[x] = arr[x - 2] + arr[x - 3];
	}
	int C;
	cin >> C;
	int temp;
	while (C--) {
		cin >> temp;
		cout << arr[temp] << "\n";
	}
	return 0;
}