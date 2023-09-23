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

const int INF = 2000000000;

void solve() {
	int n;
	cin >> n;
	vector<int> music(n+1, 0);
	vector<vector<int>> dp(n+1, vector<int>(n+1, INF));
	for(int i = 1; i <= n; i++) cin >> music[i];

	dp[1][0] = 0;
	dp[0][1] = 0;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(i == j) continue;
			int newMusic = max(i, j) + 1;
			dp[newMusic][j] = min(dp[newMusic][j], dp[i][j] + abs((i != 0 ? music[newMusic] - music[i]: 0)));
			dp[i][newMusic] = min(dp[i][newMusic], dp[i][j] + abs(j != 0 ? music[newMusic] - music[j]: 0));
		}
	}
	int res = INF;

	for(int i = 0; i < n; i++) {
		res = min(res, dp[i][n]);
		res = min(res, dp[n][i]);
	}
	debug(dp);
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
