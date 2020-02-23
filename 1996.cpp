#include <iostream>
#include <string>

using namespace std;
int T;
string arr[1001];
int intMap[1001][1001];
int mx[8] = {1,1,0,-1,-1,-1,0,1};
int my[8] = { 0,-1,-1,-1,0,1,1,1 };
void MkMap(int x,int y) {
	int sum = 0;
	if (arr[x][y] > '0' && arr[x][y] <= '9') {
		intMap[x][y] = -1;
	}
	else {
		for (int i = 0; i < 8; i++) {
			if (x + mx[i] >= 0 && x + mx[i] < T && y + my[i] >= 0 && y + my[i] < T) {
				if(arr[x + mx[i]][y + my[i]] >= '0' && arr[x + mx[i]][y + my[i]]<='9')
					sum += (arr[x + mx[i]][y + my[i]] - '0');
			}
		}
		intMap[x][y] = sum;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	for (int x = 0; x < T; x++) {
		cin >> arr[x];
	}
	for (int x = 0; x < T; x++) {
		for (int y = 0; y < T; y++) {
			MkMap(x,y);
		}
	}
	for (int x = 0; x < T; x++) {
		for (int y = 0; y < T; y++) {
			if (intMap[x][y] == -1) {
				cout << '*';
			}
			else if (intMap[x][y] > 9) {
				cout << "M";
			}
			else {
				cout << intMap[x][y];
			}
		}
		cout << "\n";
	}
	return 0;
}