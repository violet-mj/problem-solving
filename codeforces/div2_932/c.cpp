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
	lint n, c; cin >> n >> c;
	vector<lint> v(n);
	lint addv = 0;
	lint diffv = 0;
	lint total = (c + 1) * (c + 2) / 2LL;
	vector<vector<lint>> parity(2);
	for(int i = 0; i < n; i++) {
		cin >> v[i];
		parity[v[i] % 2LL].pb(v[i]);
		addv += v[i] / 2LL + 1LL;
		diffv += c - v[i] + 1;
	}

	lint common = 0LL;

	for(lint i = 0; i < n; i++) {
		lint nn = parity[v[i] % 2LL].size();
		lint l = -1;
		lint r = nn;

		while(l + 1 < r) {
			lint mid = (l + r)	>> 1;
			if(parity[v[i] % 2LL][mid] <= v[i]) {
				l = mid;
			} else {
				r = mid;
			}
		}
		common += r;
		debug(r, v[i]);
	}

	debug(total, addv, diffv, common);

	cout << total - (addv + diffv - common) << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) 
	solve();
}
