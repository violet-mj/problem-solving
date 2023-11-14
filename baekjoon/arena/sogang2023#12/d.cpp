#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <utility>
#include <cmath>

using namespace std;

#ifndef ONLINE_JUDGE
#include "/Users/mj/.vim/template/debug.cpp"
#else
#define debug(x...)
#endif

typedef long long lint;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<lint, lint> pll;
typedef vector<int> vi;
typedef vector<lint> vl;

#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl "\n"
#define all(v) (v).begin(),(v).end()

lint gcd(lint a, lint b) {
	while(b != 0) {
		a = a % b;	
		swap(a, b);
	}
	return a;
}

void solve() {
	lint x, y;
	cin >> x >> y;
	if(x == y) {
		cout << 0 << "\n";
		return;
	}

	if(x > y) {
		if(gcd(x, y) != 1)	 {
			cout << 1 << "\n";
			cout << y - x << "\n";
			return;
		}
	}

	lint lcmv = x * y / gcd(x, y);

	if(lcmv == y) {
		cout << 1 << "\n"	;
		cout << lcmv - x << "\n";
		return;
	}
	cout << 2 << "\n";
	cout << lcmv - x << "\n";
	cout << y - lcmv << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
