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
	lint n, m; cin >> n >> m;		
	vector<lint> ai(n + 1, 0);
	vector<lint> bi(n + 1, 0);

	for(int i = 1; i <= n; i++) {
		cin >> ai[i];
	}
	for(int i = 1; i <= n; i++) {
		cin >> bi[i];
	}
	vector<lint> pbi(n + 1);

	for(int i = 1; i <= n; i++) {
		pbi[i] = pbi[i - 1] + bi[i];
	}

	vector<vector<lint>> dp(n + 2, vector<lint>(2, 0));
	dp[0][0] = 1LL << 60;
	dp[0][1] = 1LL << 60;

	for(int i = n; i >= 1; i--) {
		dp[i][0] = min(dp[i + 1][0], dp[i + 1][1]) + ai[i];
		if(i == 1) {
			dp[i][1] = 1LL << 60;
		} else {
			dp[i][1] = min(dp[i + 1][0], dp[i + 1][1]) + bi[i];
		}
	}

	lint res = dp[m][0];

	for(int i = m - 1; i >= 0; i--) {
		res = min({res, dp[i][0]});
	}

	debug(dp);

	cout << res << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) solve();
}
