#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct Stu {
	int Pro, Panal;
};
bool cmp(Stu &a, Stu &b) {
	if (a.Pro == b.Pro) return a.Panal < b.Panal;
	else return a.Pro > b.Pro;
}
Stu v1[67];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	for (int x = 0; x < T; x++) {
		cin >> v1[x].Pro >> v1[x].Panal;
	}
	sort(v1, v1 + T,cmp);
	int Giver = 0;
	for (int x = 5; x < T; x++) {
		if (v1[x].Pro == v1[4].Pro)
			Giver++;
	}
	cout << Giver << "\n\n";
	return 0;
}