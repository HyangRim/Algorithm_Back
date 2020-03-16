#include <iostream>
#include <vector>
using namespace std;
int N, B, C;
long long ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	vector<int> v1(N);
	for (int x = 0; x < N; x++) {
		cin >> v1[x];
	}
	cin >> B >> C;
	int tmp = 1;
	for (int x = 0; x < N; x++) {
		v1[x] -= B;
		ans++;

		if (v1[x] > 0) {
			if (v1[x] % C == 0) {
				ans += (v1[x] / C);
			}
			else {
				ans += ((v1[x] / C) + 1);
			}
		}
	}
	cout << ans;
	return 0;
}