#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int N, M;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	while (true) {
		cin >> N >> M;
		if (cin.eof()) break;
		int Count = 0;
		for (int x = N; x <= M; x++) {
			int temp = x;
			if (temp < 10) {
				Count++;
			}
			else {
				vector<int> v1;
				bool Correct = true;
				while (temp) {
					if (!v1.empty()) {
						if (v1.end() != find(v1.begin(), v1.end(), temp % 10)) {
							Correct = false;
							break;
						}
					}
					v1.push_back(temp % 10);
					temp /= 10;
				}
				if (Correct) Count++;
			}
		}
		cout << Count << "\n";
	}
	return 0;
}