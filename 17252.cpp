#include <iostream>

using namespace std;
int N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	if (!N) {
		cout << "NO";
		return 0;
	}
	while (N) {
		if (N % 3 > 1) {
			cout << "NO";
			return 0;
		}
		N /= 3;
	}
	cout << "YES";
	return 0;
}