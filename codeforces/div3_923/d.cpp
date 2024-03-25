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
	int n, q;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++) cin >> v[i];
	v.pb(-10000000);
	cin >> q;
	vector<pii> p;
	int init = 0;
	for(int i = 1; i <= n; i++) {
		if(v[i] != v[i-1]) {
			p.pb(mp(init, i - 1));
			init = i;
		}
	}

	debug(p);

	for(int i = 0; i < q; i++) {
		int l, r;	cin >> l >> r;
		l--; r--;

		int ll = -1;
		int rr = p.size();
		int res1 = -1;
		int res2 = -1;

		while(1)  {
			int mid = (ll + rr) >> 1;	

			if(l >= p[mid].f && l <= p[mid].s) {
				res1 = mid;	
				break;
			} else if(p[mid].f > l) {
				rr = mid;	
			} else if(p[mid].s < l){
				ll = mid;	
			}
		}


		ll = -1;
		rr = p.size();

		while(1)  {
			int mid = (ll + rr) >> 1;	
			debug(ll, rr);

			if(r >= p[mid].f && r <= p[mid].s) {
				res2 = mid;	
				break;
			} else if(p[mid].f > r) {
				rr = mid;	
			} else if(p[mid].s < r){
				ll = mid;	
			}
		}

		debug(res1, res2, res1 == res2);
		
		if(res1 == res2) {
			cout << "-1 -1\n";
		} else {
			cout << p[res2 - 1].s + 1 << " " << p[res2].f + 1 << "\n";
		}
	}
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) 
	solve();
}
