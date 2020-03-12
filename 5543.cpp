#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;



int main() {
	vector<int> v1;
	vector<int> v2;
	int temp;
	for (int x = 0; x < 3; x++) {
		cin >> temp;
		v1.push_back(temp);
	}
	for (int x = 0; x < 2; x++) {
		cin >> temp;
		v2.push_back(temp);
	}
	int set = *min_element(v1.begin(), v1.end()) + *min_element(v2.begin(), v2.end());
	cout << set - 50;
	return 0; 
}