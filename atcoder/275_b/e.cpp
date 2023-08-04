
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

#ifdef DEBUG
#define debug 1
#else
#define debug 0
#endif

#define mp make_pair 
#define pb push_back 
#define f first 
#define s second

typedef long long ll;

ll n, m, k;
const ll MOD = 998244353;


ll bigMultiply(ll a, ll b) {
	if(b == 0) {
		return 1;	
	}

	ll mid = bigMultiply(a, b / 2) % MOD;
	mid %= MOD;
	if(b % 2 == 1) {
		return (mid * mid % MOD) * (a % MOD) % MOD;
	} else {
		return mid * mid % MOD; 
	}
}

void solve() {
	cin >> n >> m >> k;	

	ll dp[k+1][n+1];
	ll inv_m = bigMultiply(m, MOD - 2);

	fill(&dp[0][0], &dp[k][n+1], 0);

	dp[0][0] = 1;
	
	ll res = 0;

	for(int i = 0; i < k; i++) {
		for(int j = 0; j <= n; j++) {
			for(int z = 1; z <= m; z++) {
				int k = j + z <= n ? j + z : 2 * n - (j + z) ;
				if(j == n) k = n;
				dp[i+1][k] += (dp[i][j]); 
				dp[i+1][k] %= MOD;
			}
		}
	}

  for(int i = 0; i < k + 1; i++) {
	  for(int j = 0; j <= n; j++) {
		  cout << dp[i][j] << " ";
	  }	
	  cout << "\n";
  }

	for(int i = 0; i <= n; i++) {
		res += (dp[k][i]) % MOD;
		res %= MOD;
	}

	cout << dp[k][n] * bigMultiply(res, MOD - 2) % MOD << "\n";
	
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	solve();
}
