#include <iostream>

using namespace std;
int N;
unsigned long long ans[1001];
int main() {
	cin >> N;
	ans[1] = 3;
	ans[2] = 12;
	for (int x = 3; x <= 1000; x++) {
		int temp = 0;
		for (int y = 1; y <= x; y++) {
			temp += y;
			temp += x;
		}
		temp += x;
		ans[x] =  ans[x-1]+ temp;
	}
	cout << ans[N];
	return 0;
}