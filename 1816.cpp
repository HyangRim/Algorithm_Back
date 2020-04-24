#include <iostream>
#include <vector>
using namespace std;
int N;
const int MAX = 1e6 + 1;
unsigned long long Num;
int era[MAX];
vector<int> prime;
void eratos() {
	era[0] = era[1] = -1;

	for (int x = 2; x < MAX; x++) {
		era[x] = x;
	}
	for (int x = 2; x*x < MAX; x++) {
		if (era[x] == x) {
			for (int y = x * x; y < MAX; y += x) {
				if (era[y] == y) {
					era[y] = x;
				}
			}
		}
	}
	for (int x = 2; x < MAX; x++) {
		if (era[x] == x) {
			prime.push_back(x);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	eratos();
	for (int x = 0; x < N; x++) {
		cin >> Num;

		bool flag = true;
		int sz = prime.size();
		for (int y = 0; y < sz; y++) {
			if (Num % prime[y] == 0) {
				flag = false;
				break;
			}
		}


		if (flag) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
	return 0;
}