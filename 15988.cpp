#include <iostream>
#include <algorithm>
using namespace std;

long long arr[1000002];
int main() {

	int C;
	cin >> C;
	int temp;
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;
	arr[4] = 7;
	for (int x = 5; x < 1000001; x++) {
		arr[x] = (arr[x - 1] + arr[x - 2] + arr[x - 3]) % 1000000009;
	}
	while (C--) {
		cin >> temp;
		cout << arr[temp] << "\n";
	}
	return 0;
}