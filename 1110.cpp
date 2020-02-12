#include <iostream>

using namespace std;
int N;
int main() {
	cin >> N;
	
	int temp = N;
	int ans = 0;
	while (1) {
		int one = (temp / 10 + temp % 10)%10;
		temp = (temp % 10) * 10 + one;
		ans++;
		//cout << temp << "\n";
		if (N == temp) break;
	}
	cout << ans;
	

	return 0;
}