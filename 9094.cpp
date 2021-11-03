#include <iostream>
#include <cmath>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	while (T--) {
		int temp = 0;
		int N, M;
		cin >> N >> M;
		for (int i = 1; i < N; i++) {//a
			for (int j = i+1; j < N; j++) {//b
				double a = i;
				double b = j;
				double tmp = (pow(a, 2) + pow(b, 2) + double(M)) / (a * b);
				if ((tmp - (int)tmp) == 0) {
					temp++;
				}
			}
		
		}
		cout << temp << "\n";
	}
	return 0;
}