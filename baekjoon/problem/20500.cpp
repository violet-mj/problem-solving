#include <iostream>
using namespace std;

int n;
long long dp[1516][15];
long long re10[1516];
const long long MOD = 1000000007;

void solve() {
	cin >> n;
	re10[0] = 1LL;
	for(int i = 1; i < 1516; i++) {
		re10[i] = re10[i-1] * 10LL % 15;
	}
	
	int a[2] = {1, 5};
	fill(&dp[0][0], &dp[1515][15], 0);
	dp[0][1] = 1LL;
	dp[0][5] = 1LL;
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 15; j++) {
			for(int z: a) {
				long remain = (j + z * re10[i+1] % 15LL) % 15LL;
				dp[i+1][remain] = (dp[i+1][remain] + dp[i][j]) % MOD;
			}
		}
	}
	
	cout << dp[n-1][0] << "\n";
	
}

int main() {
	solve();
	return 0;
}
