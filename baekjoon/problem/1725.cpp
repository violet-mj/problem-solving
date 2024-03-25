#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <utility>
#include <stack>
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
	vector<lint> v(n);
	stack<pll> stk;
	stk.push(mp(0, 0));
	lint res = 0LL;
	for(int i = 0; i < n; i++) cin >> v[i];
	for(int i = 0; i < n; i++) {
		debug(res);
		int ss = stk.size();
		if(v[i] >= stk.top().s) {
			stk.push(mp(i+1, v[i]));
		} else {
			int lastIdx = stk.top().f;
			while(stk.top().s > v[i]) {
				lint currIdx = stk.top().f;
				lint currHeight = stk.top().s;
				res = max(res, currHeight * (lastIdx + 1 - currIdx));
				stk.pop();
			}
			stk.push(mp(i+1, v[i]));
		}
	}

	lint lastIdx = 0;

	if(stk.size() != 0) {
		lastIdx = stk.top().f;
	}

	while(!stk.empty()) {
		lint currIdx = stk.top().f;
		lint currHeight = stk.top().s;
		res = max(res, currHeight * (currIdx));
		stk.pop();
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
