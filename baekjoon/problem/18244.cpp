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

#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl "\n"

int n, t;
const lint MOD = 1000000007;

void solve() {
	cin >> n;

	lint dp[n+1][10][5];

	fill(&dp[0][0][0], &dp[n][9][5], 0);

	for(int i = 0; i <= 9; i++) {
		dp[1][i][0] = 1LL;
	}

	for(int i = 1; i <= n; i++) {
		for(int j = 0; j <= 9; j++)	 {
			if(j > 0)	 {
				dp[i][j][1]	+= (dp[i-1][j-1][3] + dp[i-1][j-1][4] + dp[i-1][j-1][0]);
				dp[i][j][1] %= MOD;
				dp[i][j][2] += dp[i-1][j-1][1];
				dp[i][j][2] %= MOD;
			}

			if(j < 9) {
				dp[i][j][3] += (dp[i-1][j+1][1] + dp[i-1][j+1][2] + dp[i-1][j+1][0]);
				dp[i][j][3] %= MOD;
				dp[i][j][4] += dp[i-1][j+1][3];
				dp[i][j][4] %= MOD;
			}
		}
	}

	lint res = 0;

	// for(int i = 1; i <= n; i++) {
		// for(int j = 0; j <= 9; j++)	 {
			// cout << dp[i][j] << " ";
		// }
		// cout << "\n";
	// }
	
	for(int i = 0; i <= 9; i++) {
		for(int j = 0; j < 5; j++) {
			res += dp[n][i][j];
			res %= MOD;
		}
	}
	cout << res << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
