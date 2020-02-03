#include <iostream>
#include <string>
#include <stack>


using namespace std;
string str;
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	while (1) {
		getline(cin, str);
		stack<char> st;
		bool isright = true;
		if (str == ".") return 0;

		int len = str.size();

		for (int x = 0; x < len; x++) {
			if (str[x] == '[') {
				st.push('[');
			}
			else if (str[x] == ']') {
				if (!st.empty() && st.top() == '[')
					st.pop();
				else {
					isright = false;
					break;
				}
			}
			else if (str[x] == '(') {
				st.push('(');
			}
			else if (str[x] == ')') {
				if (!st.empty() && st.top() == '(')
					st.pop();
				else {
					isright = false;
					break;
				}
			}
		}
		if (isright && st.empty()) {
			cout << "yes\n";
		}
		else {
			cout << "no\n";
		}
	}
	return 0;
}