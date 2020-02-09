#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int N;
int arr[12], operato[4];

int maxresult = -987654321;
int minresult = 987654321;

void DFS(int add,int minu,int mul,int div,int x,int sum) {
	if (x == N) {
		maxresult = max(maxresult, sum);
		minresult = min(minresult, sum);
	}

	if (add > 0) {
		DFS(add - 1,minu,mul,div, x + 1,sum + arr[x]);
	}
	if(minu > 0)
		DFS(add, minu-1, mul, div, x + 1, sum - arr[x]);
	if(mul > 0)
		DFS(add, minu, mul-1, div, x + 1, sum * arr[x]);
	if(div>0)
		DFS(add, minu, mul, div-1, x + 1, sum / arr[x]);
}
int main() {
	cin >> N;
	for (int x = 0; x < N; x++) {
		cin >> arr[x];
	}
	for (int x = 0; x < 4; x++) {
		cin >> operato[x];
	}
	DFS(operato[0], operato[1], operato[2], operato[3], 1,arr[0]);
	cout << maxresult << "\n" << minresult;
	return 0;
}