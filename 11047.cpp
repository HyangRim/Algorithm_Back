#include <iostream>

using namespace std;
int Coin[11];
int main() {
	int N, K;
	cin >> N >> K;
	for (int x = 0; x < N; x++) {
		cin >> Coin[x];
	}
	int ans = 0;
	while (N--) {
		if (K / Coin[N] > 0) {
			ans += K / Coin[N];
			K %= Coin[N];
			//cout << Coin[X] << "\n";
			//cout << ans << "\n";
		}
	}
	cout << ans;
	return 0;
}