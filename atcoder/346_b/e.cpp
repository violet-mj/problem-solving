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
	lint h, w, m; cin >> h >> w >> m;		
	vector<vector<lint>> comm;
	vector<vector<lint>> row;
	vector<vector<lint>> col;
	vector<lint> checkRow(h + 1, 0);
	vector<lint> checkCol(w + 1, 0);
	for(int i = 0; i < m; i++) {
		lint cmd, a, x;
		cin >> cmd >> a >> x;
		comm.pb({cmd, a, x});
	}

	for(int i = m - 1; i >= 0; i--) {
		vector<lint> curr = comm[i];

		if(curr[0] == 1) {
			if(checkRow[curr[1]]) continue;
			row.pb({m - 1 - i, curr[1], curr[2]});
			checkRow[curr[1]] = 1;
		} else {
			if(checkCol[curr[1]]) continue;
			col.pb({m - 1 - i, curr[1], curr[2]});
			checkCol[curr[1]] = 1;
		}
	}

	int cs = col.size();
	int rs = row.size();

	map<int, lint> res;

	for(int i = 0; i < row.size(); i++) {
		int l = -1;	
		int r = cs;
		vector<lint> currRow = row[i];

		while(l + 1 < r) {
			int mid = (l + r)	 >> 1;
			if(col[mid][0] > currRow[0]) {
				r = mid;	
			} else {
				l = mid;	
			}
		}
		res[currRow[2]] += w - (cs - r);
	}

	for(int i = 0; i < cs; i++) {
		int l = -1;	
		int r = rs;
		vector<lint> currCol = col[i];

		while(l + 1 < r) {
			int mid = (l + r)	>> 1;
			if(row[mid][0] > currCol[0]) {
				r = mid;	
			} else {
				l = mid;	
			}
		}
		res[currCol[2]] += h - (rs - r);
	}

	lint entire = 0LL;

	vector<pll> ans;


	for(auto value: res) {
		if(value.f == 0) continue;
		ans.pb(mp(value.f, value.s));
		entire += value.s;
	}

	ans.pb({0, (lint) h * w - entire});

	sort(all(ans), [&](pll p1, pll p2) {
		if(p1.s == p2.s)	 {
			return p1.f < p2.f;
		}
		return p1.s > p2.s;
	});
	cout << ans.size() << "\n";
	for(int i = 0; i < ans.size(); i++) {
		cout << ans[i].f << " " << ans[i].s << "\n";
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
