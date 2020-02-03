#include <iostream>
#include <algorithm>
using namespace std;
struct Problem {
	int Point, Num;
};

bool cmp(Problem a,Problem b) {
	return a.Point > b.Point;
}
int sum;
Problem Qz[8];
int Rank[5];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int Temp;
	for (int x = 0; x < 8; x++) {
		cin >> Temp;
		Qz[x].Point = Temp;
		Qz[x].Num = x + 1;
	}
	sort(Qz, Qz + 8, cmp);
	for (int x = 0; x < 5; x++) {
		sum += Qz[x].Point;
	}
	cout << sum << "\n";
	for (int x = 0; x < 5; x++) {
		Rank[x] = Qz[x].Num;
	}
	sort(Rank, Rank + 5);
	for (int x = 0; x < 5; x++) {
		cout << Rank[x] << " ";
	}
	return 0;
}