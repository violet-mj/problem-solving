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


const lint INF = 1LL << 60;

struct cmp {
	bool operator () (pll p1, pll p2) {
		return p1.s < p2.s;
	}
};

void solve() {
	int n, d;		
	cin >> n >> d;

	vector<int> value(n);
	vector<lint> dp(n, -INF);

	priority_queue<pll, vector<pll>, cmp> pq;

	for(int i = 0; i < n; i++) cin >> value[i];
	for(int i = 0; i < n; i++) {
		lint k = -INF;
		while(!pq.empty()) {
			pll curr = pq.top();	
			if(i - curr.f <= d) {
				k = curr.s;	
				break;
			} else {
				pq.pop();	
			}
		}
		dp[i] = max(k + (lint)value[i], (lint)value[i]);
		pq.push(mp(i, dp[i]));
	}

	debug(dp);

	cout << *max_element(all(dp)) << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
