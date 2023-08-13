#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <cctype>

using namespace std;

#ifdef DEBUG
#define debug 1
#else
#define debug 0
#endif

#define mp make_pair 
#define pb push_back 
#define f first 
#define s second

string s[3];

bool isNumeric(std::string const &str)
{
    auto it = str.begin();
    while (it != str.end() && std::isdigit(*it)) {
        it++;
    }
    return !str.empty() && it == str.end();
}


void solve() {
	int target;	

	for(int i = 0; i < 3; i++) {
		cin >> s[i];
		if(isNumeric(s[i])) {
			target = stoi(s[i]) + 3 - i;
		}
	}

	if(target % 15 == 0) {
		cout << "FizzBuzz" << "\n";
	} else if(target % 3 == 0) {
		cout << "Fizz" << "\n";
	} else if(target % 5 == 0) {
		cout << "Buzz" << "\n";
	} else {
		cout << target << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}
