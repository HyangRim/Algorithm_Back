#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <cmath>
using namespace std;


int numa = 7500001;
bool prime[7500001];
int main()
{
	int K;
	cin >> K;
	memset(prime, 1, sizeof(prime));
	prime[0] = prime[1] = true;
	int sqrtx = int(sqrt(numa));

	for (int x = 2; x <= sqrtx; x++) {
		if (prime[x])
			for (int y = x * x; y <= numa; y += x)
				prime[y] = false;
	}
	int ans = 0;
	for (int x = 2; x <= numa; x++) {
		if (prime[x]) ans++;
		if (ans == K) {
			cout << x;
			break;
		}
	}
}
