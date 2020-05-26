#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	vector<long long> v1(N);
	for (int x = 0; x < N; x++) {
		cin >> v1[x];
	}
	cout << v1[0] << " ";
	long long sum = v1[0];
	for (int x = 1; x < N; x++) {
		long long ans = ((v1[x] * (x + 1)) - sum);
		sum += ans;
		cout << ans << " ";
	}
	return 0;
}