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
	int n,x,y; cin >> n >> x >> y;
	vector<lint> v(n);
	vector<pll> vp(n);
	map<pll, lint> m;

	for(int i = 0; i < n; i++) {
		cin >> v[i];
		vp[i] = mp(v[i] % x, v[i] % y);
	}
	debug(vp);

	for(int i = 0; i < n; i++) {
		m[vp[i]]++;
	}

	lint cnt = 0LL;

	debug(m);

	for(const auto& [key, value]: m) {
		lint xm = key.f; lint ym = key.s;
		if(xm == x - xm) {
			cnt += (value) * (value - 1);
		} else {
			cnt += value * (m[mp(x - xm, ym)]);
		}

		if(xm == 0) {
			cnt += value * (value - 1LL);
		}
	}

	cout << cnt / 2LL << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) 
	solve();
}
