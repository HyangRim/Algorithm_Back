#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int A, T, want;
int Person_count = 0;
int N = 0;
int gcount = 0;
int main() {
	cin >> A >> T >> want;

	while (1) {
		N++;
		vector<int> game{ 0,1,0,1 };

		for (int x = 0; x <= N; x++)game.push_back(0);
		for (int x = 0; x <= N; x++)game.push_back(1);
		for (int x = 0; x < game.size(); x++) {
			if (game[x] == want) gcount++;
			if (gcount == T) {
				cout << Person_count;
				return 0;
			}
			Person_count++;
			Person_count %= A;
		}
		game.clear();
	}
	return 0;
}