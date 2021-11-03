#include <iostream>

using namespace std;
int N, M;
int psum[100001];
int arr[100002];
int sum[100001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for (int x = 1; x <= N; x++) {
		cin >> psum[x];
	}

	for (int x = 0; x < M; x++) {
		int a, b, k;
		cin >> a >> b >> k;//1 5 -3
		arr[a] += k;// arr[1] += -3
		arr[b + 1] -= k; // arr[6] += 3
	}
	for (int x = 1; x <= N; x++) {
		sum[x] = sum[x - 1] + arr[x];
		//cout << sum[x] << " ";
	}
	for (int x = 1; x <= N; x++) {
		psum[x] += sum[x];
		cout << psum[x] << " ";
	}
	return 0;
}