#include <stack>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;
string s;

int main() {
	getline(cin,s);
	s += "\n";

	stack<char> st;
	bool check = false;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '<') {
			while (!st.empty()) {
				cout << st.top();
				st.pop();
			}
			cout << "<";
			check = true;
		}
		else if (s[i] == '>') {
			cout << ">";
			check = false;
		}

		else if (check) cout << s[i];
		else if (s[i] == ' ' || s[i] == '\n') {
			while (!st.empty()) {
				cout << st.top();
				st.pop();
			}
			cout << " ";
		}
		else st.push(s[i]);
	}

	return 0;
}