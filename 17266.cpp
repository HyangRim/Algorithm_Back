#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int N, M;
int arr[100001] = { 0, };

bool Check(vector<int>& v1, int height) {
	int len = v1.size();
	int ds = 0;
	for (int x = 0; x < len; x++) {//���ε� ��ġ �ϳ��ϳ� ���鼭
		if (v1[x] - height <= ds) {//ù ���ε��� ��ο� �κ��� ������ 0. v1[x]-height�� 0�� �Ǿ��� ����� �������� ��. 
			ds = v1[x] + height;//���� ��� ������.
		}
		else {
			break;//��ο� �κ� ������ break.
		}
	}
	return N - ds <= 0;//�ؼ� ���������� true, false
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	int tmp;
	vector<int> v1(M);
	for (int x = 0; x < M; x++) {
		cin >> v1[x];//��ġ �ޱ�.
	}

	int left = 1, right = N;
	int mid, ans = 0;

	while (left <= right) {
		mid = (left + right) / 2;//1 ~ N���� Ž��
		if (Check(v1, mid)) {//���� �Ǹ�...
			ans = mid;
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	cout << ans << "\n";
	return 0;
}