#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
long long arr[101];

int gcd(long long a, long long b) {
	return b ? gcd(b, a%b) : a;
}

int main() {

	int N, i, t;
	long long n;
	vector<int> v;

	cin >> N;
	for (i = 0; i < N; i++) cin >> arr[i];

	sort(arr, arr + N);

	n = arr[1] - arr[0];
	for (i = 2; i < N; i++) {
		n = gcd(n, arr[i] - arr[i - 1]);
	}

	for (i = 2; i*i <= n; i++) {
		if (n % i == 0) {
			v.push_back(i);
			v.push_back(n / i);
		}
	}

	v.push_back(n);
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	for (i = 0; i < v.size(); i++) printf("%d ", v[i]);
	printf("\n");
	return 0;
}