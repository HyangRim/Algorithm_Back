#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int T;
unsigned long long n, a, b;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	
	while (T--) {
		cin >> n >> a >> b;
		long long temp = min(a, b);
		long long K = 2;
		long long ans = 0;
		while (1) {
			if (K > temp) {
				K /= 2;
				break;
			}
			else {
				ans++;
				K *= 2;
			}
		}
		while (1) {
			if (temp % K == 0)break;
			else {
				K /= 2;
				ans--;
			}
		}
		cout << n - ans << "\n";
	}

	return 0;
}