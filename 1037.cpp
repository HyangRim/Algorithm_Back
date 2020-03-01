#include <iostream>
#include <algorithm>
using namespace std;
int N;
int arr[51];
int main() {
	cin >> N;
	for (int x = 0; x < N; x++) {
		cin >> arr[x];
	}
	if (N == 1) {
		cout << arr[0] * arr[0];
		return 0;
	}
	sort(arr, arr + N);
	cout << arr[0] * arr[N - 1];
	return 0;
}