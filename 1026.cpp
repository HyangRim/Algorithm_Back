#include <iostream>
#include <algorithm>
using namespace std;
int A[51];
int B[51];
int Sum;
bool cmp(int x,int y) {
	return x > y;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int S;
	cin >> S;
	for (int x = 0; x < S; x++) {
		cin >> A[x];
	}
	for (int x = 0; x < S; x++) {
		cin >> B[x];
	}
	sort(A, A + S);
	sort(B, B + S, cmp);
	for (int x = 0; x < S; x++) {
		Sum += A[x] * B[x];
	}
	cout << Sum;
	return 0;
}