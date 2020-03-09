#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	vector<long long> Ai(N);
	vector<long long> Bi(N);
	for (int x = 0; x < N; x++) {
		cin >> Ai[x];
	}
	for (int x = 0; x < N;x++) {
		cin >> Bi[x];
	}
	long long ans;
	for (int x = 0; x < N; x++) {
		ans = upper_bound(Bi.begin(), Bi.end(), Ai[x]) - (Bi.begin() + x) - 1;
		cout << ans << " ";
	}
	return 0;
}