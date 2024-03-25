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
	lint n; cin >> n;		
	vector<lint> v(n);
	for(int i = 0; i < n; i++) cin >> v[i];
	vector<lint> stk;
	lint cnt = 0;
	for(int i = 0; i < n; i++) {
		if(stk.empty()) {
			stk.pb(v[i]);
		} else {
			bool flag = false;
			while(v[i] > stk[stk.size() - 1] && !stk.empty()) {
				flag = true;
				cnt += 2LL;	
				stk.pop_back();
			}
			stk.pb(v[i]);
		}
		debug(i, cnt, stk);
	}

	cnt += max(0LL, (lint)stk.size() - 1);
	cout << cnt << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
