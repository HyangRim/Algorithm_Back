#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;
int N, a, b;
vector<int> v1[500001];
bool visited[500001];
int heightcount = 0;

void dfs(int start, int height) {
	bool isLeaf = true;//�������鼭 �ڽ��� ���� ���� true�ϱ�. 
	visited[start] = true;//�湮��. 
	for (auto x = v1[start].cbegin(); x != v1[start].cend(); x++) {//ex)1���� 2,3�̶�� �ڽĳ�尡 ����.
		if (!visited[*x]) isLeaf = false, dfs(*x, height + 1);//1�� ������쿡 �װ� �湮 ����. �׷��� ������尡 �ƴ�. �� ���� ���� ��. height+1��. 
	}
	if (isLeaf) heightcount += height;//���ƿͼ� left��尡 �Ǹ� �� �Ʒ��� ������� height�� countheight�� �־���. 
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int x = 1; x < N; x++) {
		cin >> a >> b;
		v1[a].push_back(b);
		v1[b].push_back(a);
	}
	dfs(1, 0);//�� �� ��ƮƮ������ ������ �������鼭 height�� �÷����� ����.
	cout << (heightcount % 2 ? "Yes" : "No");
	return 0;
}