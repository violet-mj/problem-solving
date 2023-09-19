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

int n;

void solve() {
	cin >> n;	
	vector<pll> dragons(n);
	vector<vector<lint>> dp(n+1, vector<lint>(n+1, 0));

	for(int i = 0; i < n; i++) {
		cin >> dragons[i].f >> dragons[i].s;	
	}

	sort(all(dragons), [](pii p1, pii p2) {
		return p1.f < p2.f	;
	});

	debug(dragons);

	for(int i = 1; i <= n; i++) {
		for(int j = i; j <= n; j++)	 {
			debug(i, j, dragons[j-1]);
			dp[i][j] = max(dp[i][j-1], dp[i-1][j-1] + dragons[j-1].s + dragons[j-1].f * (i - 1));
		}
	}

	debug(dp);

	for(int i = 1; i <= n; i++) {
		cout << dp[i][n] << "\n";
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
