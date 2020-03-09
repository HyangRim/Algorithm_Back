#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int L, R;
	cin >> L >> R;
	int leng = 0;
	int branch = 2;
	while (1) {
		L = (int)(L *((double)R / 100));
		if (L <= 5) break;
		leng += (L*branch);
		branch *= 2;
	}
	cout << leng;
	return 0; 
}