#include <iostream>
#include <queue>

using namespace std;

int arr[101];
bool visited[101];

int N, M;
int a, b;
int roll[6] = { 1,2,3,4,5,6 };
struct node {
	int now, cot;
};

void bfs()
{
	queue<node> que;

	que.push({ 1,0 });
	visited[1] = true;

	while (!que.empty())
	{
		int nnow = que.front().now;
		int ncot = que.front().cot;

		que.pop();

		if (nnow == 100) {
			cout << ncot;
			return;
		}

		for (int i = 0; i < 6; i++)
		{
			int mnow = nnow + roll[i];

			if (mnow >= 1 && mnow <= 100 && !visited[mnow]) {
				if (arr[mnow])
				{
					visited[mnow] = true;
					visited[arr[mnow]] = true;
					mnow = arr[mnow];
				}
				else
				{
					visited[mnow] = true;
				}
				que.push({ mnow, ncot + 1 });
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for (int x = 0; x < N + M; x++) {
		cin >> a >> b;
		arr[a] = b;
	}

	bfs();
	return 0;
}