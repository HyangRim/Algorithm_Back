#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;
int N, M;
int r, c, d;
int map[51][51];
bool visited[51][51];

int dx[4] = {-1,0,1,0};//왼,위,오른, 아래
int dy[4] = {0,1,0,-1};

int turn_di(int d) {
	if (d == 0) return 3;
	else if (d == 1) return 0;
	else if (d == 2) return 1;
	else if (d == 3) return 2;
}
void bfs(int r,int c,int z) {

	int x = r;
	int y = c;
	int d = z;
	int Room = 0;
	map[x][y] = 2;
	Room++;

	int nx, ny, nd;

	while (1)
	{
		int Tmp_d = d;
		bool Can_Clean = false;
		int CanNotClean = 0;
		for (int i = 0; i < 4; i++)        // 왼쪽방향으로부터 4방향 차례대로 탐색
		{
			nd = turn_di(d);
			nx = x + dx[nd];
			ny = y + dy[nd];

			if (map[nx][ny] == 0)
			{
				Can_Clean = true;
				break;
			}
			else if (map[nx][ny] == 1 || map[nx][ny] == 2 || (nx < 0 || ny < 0 || nx >= N || ny >= M))
			{
				d = nd;
				CanNotClean++;
			}
		}

		if (Can_Clean == true)
		{
			map[nx][ny] = 2;
			Room++;
			d = nd;
		}

		if (CanNotClean == 4)
		{
			nx = x - dx[Tmp_d];
			ny = y - dy[Tmp_d];
			d = Tmp_d;
			if ((nx < 0 || ny < 0 || nx >= N || ny >= M) || map[nx][ny] == 1)
			{
				break;
			}
		}
		x = nx;
		y = ny;
	}
	cout << Room << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	cin >> r >> c >> d;
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < M; y++) {
			cin >> map[x][y];
		}
	}
	bfs(r,c,d);
	return 0;
}