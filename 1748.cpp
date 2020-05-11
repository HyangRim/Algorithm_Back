#include <iostream>
#include <string>
#include <vector>
using namespace std;
int N;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	long long ans = 0;
	for (int x = 1; x <= N; x++) {
		int num = x;
		int stack = 1;
		while (1) {
			if (num / 10 == 0) break;
			num /= 10;
			stack++;
		}
		ans += stack;
	}
	cout << ans;
	return 0;
}