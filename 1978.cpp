#include <iostream>

using namespace std;


int N;
int Ans;

bool is_prime[10001] = {};


int main() {
	cin >> N;
	for (int x = 2; x <= 10000; x++) {
		is_prime[x] = true;
	}
	for (int x = 2; x*x <= 10000; x++) {
		if(is_prime[x])
			for (int y = x * x; y <= 10000; y+=x) {
				is_prime[y] = false;
			}
	}
	int temp;
	for (int x = 0; x < N; x++) {
		cin >> temp;
		if (is_prime[temp]) Ans++;
	}
	cout << Ans;


	return 0;
}