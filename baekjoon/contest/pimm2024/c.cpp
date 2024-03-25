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
	lint n, q; cin >> n >> q;			
	vector<lint> v(n + 1, 0);
	vector<lint> pre;
	for(int i = 0; i < n; i++) cin >> v[i];
	pre.pb(v[0]);
	for(int i = 1; i < n; i++) {
		pre.pb(pre[i - 1] + v[i]);
	}

	lint ad = 0;
	debug(pre);

	for(int i = 0; i < q; i++) {
		lint cmd; cin >> cmd;
		if(cmd == 1) {
			lint plus; cin >> plus;
			ad -= plus;
		} else if(cmd == 2) {
			lint plus; cin >> plus;
			ad += plus;
		} else {
			lint a, b; cin >> a >> b;	
			a--; b--;
			a = (a + ad + n * 200000) % n;
			b = (b + ad + n * 200000) % n;
			lint res = 0;
			debug(ad, a, b);
			if(a <= b) {
				if(a != 0) {
					res = pre[b] - pre[a - 1];
				} else {
					res = pre[b];
				}
			} else {
				res += (pre[n - 1] - pre[a - 1]);
				res += (pre[b]);
			}
			cout << res << "\n";
		}
	}
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
