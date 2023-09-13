#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <utility>

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



lint n, m, x, p;
const lint INF = 1LL << 60;
void solve() {
	cin >> n >> m;
	lint dp[n+1][n+1][2];
	fill(&dp[0][0][0], &dp[n][n][2], -INF);
	dp[0][0][0] = m;
	dp[0][0][1] = m;

	vector<pll> left;
	vector<pll> right;

	left.pb(mp(0LL, 0LL));
	right.pb(mp(0LL, 0LL));
	for(int i = 0; i < n; i++) {
		cin >> x >> p;	
		if(x > 0) {
			right.pb(mp(x, p));
		} else {
			left.pb(mp(x, p));
		}
	}
	sort(all(left));
	reverse(all(left));
	sort(all(right));

	vector<lint> prefixLeft(left.size(), 0LL);
	vector<lint> prefixRight(right.size(), 0LL);
	for(int i = 1; i < left.size(); i++) {
		prefixLeft[i] = prefixLeft[i-1] + left[i].s;
	}
	for(int i = 1; i < right.size(); i++) {
		prefixRight[i] = prefixRight[i-1] + right[i].s;
	}
	
	for(int i = 1; i < left.size(); i++) {
		lint dist = abs(left[i].f - left[i-1].f);
		if(dp[i-1][0][0] > dist) {
			dp[i][0][0] = dp[i-1][0][0] + left[i].s - dist;
		} else {
			break;	
		}
		if(dp[i][0][0] > left[i].f) {
			dp[i][0][1] = dp[i][0][0] + left[i].f;
		}
	}

	for(int i = 1; i < right.size(); i++) {
		lint dist = abs(right[i].f - right[i-1].f);
		if(dp[0][i-1][1] > dist)	{
			dp[0][i][1]  = dp[0][i-1][1] + right[i].s - dist;
		} else {
			break;	
		}
		if(dp[0][i][1] > right[i].f) {
			dp[0][i][0]	 = dp[0][i][1] - right[i].f;
		}
	}

	for(int i = 1; i < left.size(); i++) {
		for(int j = 1; j < right.size(); j++) {
			lint leftDist = abs(left[i].f - left[i-1].f);
			lint rightDist = abs(right[j].f - right[j-1].f);
			lint leftDist2 = abs(left[i].f - right[j].f);
			lint lleft = dp[i-1][j][0] - leftDist;
			if(lleft > 0) {
				dp[i][j][0] = lleft + left[i].s;	
			}
			lint lright = dp[i][j-1][1] - rightDist;
			if(lright > 0) {
				dp[i][j][1] = lright + right[j].s;	
			}

			lint rright = dp[i][j][1];
			lint rleft = dp[i][j][0];

			if(rright > leftDist2) {
				dp[i][j][0]	= max(dp[i][j][0], rright - leftDist2);
			}

			if(rleft > leftDist2) {
				dp[i][j][1] = max(dp[i][j][1], rleft - leftDist2);
			}

		}
	}
	lint res = 0LL;
	for(int i = 0; i < left.size(); i++) {
		for(int j = 0; j < right.size(); j++)	 {
			for(int z = 0; z <= 1; z++)	 {
				if(dp[i][j][z] > 0)	 {
					res = max(res, m + prefixLeft[i] + prefixRight[j]);
				}
			}
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
