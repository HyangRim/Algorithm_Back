#include <iostream>

using namespace std;
int arr[1001];
int dp[1001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int max = 0;
	int N;
	cin >> N;
	for (int x = 0; x < N; x++) {
		cin >> arr[x];
	}
	for (int x = 0; x < N; x++) {
		int min = 0;
		for (int y = 0; y < x; y++) {//y ~ x����. 
			if (arr[x] > arr[y])// x�� y���� ũ��
				if (min < dp[y])// �׷��鼭 min������ dp[y]���� ũ��
					min = dp[y];//min���ٰ� dp[y]�ֱ�
		}
		dp[x] = min + 1;// �׸��� dp[x]�� min(dp[y])�ؼ� ��������?�ϱ�.
		if (max < dp[x])
			max = dp[x];
	}
	cout << max;
	return 0;
}