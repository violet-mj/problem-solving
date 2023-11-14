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

void solve() {
	int n, m, a, c;
	char b;
	cin >> n >> m;		

	vector<pii> check(n + 1, mp(-1, -1));

	int max_ = 0;
	int min_ = 0;

	for(int i = 0; i < m; i++) {
		cin >> a >> b >> c;	
		if(b == 'P') {
			check[a].f = c;	
		} else {
			check[a].s = c;	
		}
	}

	for(int i = 1; i <= n; i++) {
		if(check[i].f == 1 && check[i].s == 0)		 {
			min_++; max_++;	
		} else if(check[i].f == 0 || check[i].s == 1) {
			continue;		
		} else {
			max_++;	
		}
	}

	cout << min_ << " " << max_ << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
