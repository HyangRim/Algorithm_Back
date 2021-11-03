#include <iostream>
#include <string>

using namespace std;

string s;
int ssize;
bool visited[5001];

int getsmallindex(int left, int right) {
	int index = -1;
	int smallalpha = 987654321;

	for (int x = left; x <= right; x++) {
		if (!visited[x] && smallalpha > s[x]) {
			smallalpha = s[x];
			index = x;
		}
	}

	return index;
}

void dfs(int left, int right) {
	int index = getsmallindex(left, right);
	if (index == -1)return;
	visited[index] = true;
	for (int x = 0; x < ssize; x++) {
		if (visited[x])cout << s[x];
	}
	cout << "\n";

	dfs(index + 1, right);
	dfs(left, index - 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> s;
	ssize = s.size();
	dfs(0, ssize - 1);
	return 0;
}