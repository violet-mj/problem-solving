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

int gcd(int a, int b) {
	while(b!=0) {
		a = a % b;
		swap(a, b);
	}
	return a;
}

void solve() {
	int n, m;		
	cin >> n >> m;
	int g = n * m / gcd(n, m);
	int ng = g / n;
	int mg = g / m;
	debug(g);

	string res = "";

	vector<pair<int, char>> k;

	for(int i = 1; i <= g; i++)  {
		if(i % ng == 0 && i % mg == 0) {
			res += "3";
		} else if(i % ng == 0) {
			res += "1";
		} else if(i % mg == 0) {
			res += "2";
		}
	}

	cout << res << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
