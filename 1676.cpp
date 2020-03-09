#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int ans;
int main() {
	int N;
	cin >> N;
	while (N) {
		ans += N / 5;
		N /= 5;
	}
	cout << ans;
	return 0;
}