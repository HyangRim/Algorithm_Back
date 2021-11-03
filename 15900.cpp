#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;
int N, a, b;
vector<int> v1[500001];
bool visited[500001];
int heightcount = 0;

void dfs(int start, int height) {
	bool isLeaf = true;//내려가면서 자식이 없는 노드다 true하기. 
	visited[start] = true;//방문함. 
	for (auto x = v1[start].cbegin(); x != v1[start].cend(); x++) {//ex)1에는 2,3이라는 자식노드가 있음.
		if (!visited[*x]) isLeaf = false, dfs(*x, height + 1);//1로 갔을경우에 그거 방문 안함. 그러면 리프노드가 아님. 그 밑의 노드로 감. height+1함. 
	}
	if (isLeaf) heightcount += height;//돌아와서 left노드가 되면 맨 아래와 여기까지 height를 countheight에 넣어줌. 
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
	dfs(1, 0);//맨 위 루트트리에서 밑으로 내려가면서 height를 올려가는 식임.
	cout << (heightcount % 2 ? "Yes" : "No");
	return 0;
}