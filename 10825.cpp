#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int T;
struct Stu {
	string name;
	int Korean;
	int English;
	int Math;
};

bool cmp(const Stu &n1,const Stu &n2) {
	if (n1.Korean > n2.Korean) {
		return true;
	}
	else if (n1.Korean == n2.Korean) {
		if (n1.English < n2.English)
			return true;
		else if (n1.English == n2.English) {
			if (n1.Math > n2.Math)
				return true;
			else if (n1.Math == n2.Math)
				return n1.name < n2.name;
		}
	}
	return false;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	vector<Stu> v1(T);
	for (int x = 0; x < T; x++) {
		cin >> v1[x].name >> v1[x].Korean >> v1[x].English >> v1[x].Math;
	}
	sort(v1.begin(), v1.end(), cmp);
	for (int x = 0; x < T; x++) {
		cout << v1[x].name << "\n";
	}
	return 0;
}