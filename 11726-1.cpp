#include <iostream>

using namespace std;
int arr[1001];
int main() {
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 3;
	arr[4] = 5;
	for (int x = 5; x < 1001; x++) {
		arr[x] = (arr[x-1] + arr[x - 2])%10007;
	}
	int C;
	cin >> C;
	cout << arr[C];
	return 0;
}