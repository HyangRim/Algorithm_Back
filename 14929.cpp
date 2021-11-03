#include <iostream>
#include <vector>

using namespace std;


int N;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	vector<long long> v1(N + 1), pSum(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> v1[i];
		pSum[i] = pSum[i - 1] + v1[i];
	}

	long long ans = 0;
	for (int i = 2; i <= N; i++) {
		ans += v1[i] * pSum[i - 1];
	}
	cout << ans << "\n";

	return 0; 
}