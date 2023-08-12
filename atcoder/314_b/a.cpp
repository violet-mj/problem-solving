#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

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

int n, t;
string s;

void solve() {
	cin >> n;
	string s = "3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679";
	for(int i = 0; i < n + 2; i++) {
		cout << s[i];
	}

	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	solve();
}
