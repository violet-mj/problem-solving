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
	int n;
	cin >> n;
	vector<pii> values(n);			

	for(int i = 0; i < n; i++) {
		cin >> values[i].f >> values[i].s;	
	}

	int res = 0;
	int download = 0;
	int listening = 0;
	for(int i = 0; i < n; i++) {
		if(download + values[i].s <= listening) {
			download += values[i].s;	
			listening += values[i].f;
		} else {
			res += download + values[i].s - listening;	
			download += values[i].s;
			listening = download + values[i].f;
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
