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
	int n, x;		
	cin >> n >> x;
	vector<int> v(n + 1, 0);
	int loc = -1;
	for(int i = 1; i <= n; i++) {
		cin >> v[i];
		if(x == v[i]) loc = i;
	}

	int l = 1;
	int r = n + 1;
	swap(v[loc], v[1]);

	vector<pii> res;
	res.pb(mp(loc, 1));

	vector<int> visited(n + 1, 0);

	while(r - l > 1) {
		int m = (l + r)	/ 2;
		visited[m] = 1;
		if(v[m] <= x) {
			l = m;	
		} else {
			r = m;	
		}
	}
	res.pb(mp(1, l));

	cout << res.size() << "\n";
	cout << res[0].f << " " << res[0].s << "\n";
	cout << res[1].f << " " << res[1].s << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) solve();
}
