#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int N, M;

int arr[500010];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int x = 0; x < N; x++) {
		cin >> arr[x];
	}
	sort(arr, arr + N);

	cin >> M;
	int temp;
	for (int x = 0; x < M; x++) {
		cin >> temp;
		cout << binary_search(arr, arr + N, temp) << " ";

	}
	return 0;
}