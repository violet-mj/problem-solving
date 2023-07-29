#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

const string ROCK = "KCOR";
string rock;
int n, t;
const int MOD7 = 1000000007;


void solve() {
	cin >> n >> rock;
	long dp[5][n+1];
	vector<long> v;
	
	long init = 1;
	for(int i = 0; i <= 1000000; i++){
		v.push_back(init);
		init = (init * 2L) % MOD7;
	}
	
	
	fill(&dp[0][0], &dp[0][n+1], 1);
	fill(&dp[1][0], &dp[4][n+1], 0);

	long res = 0;
	for(int i = 1; i < 5; i++) {
		for(int j = n-1; j >= 0; j--) {
			if (ROCK[i-1] == rock[j]) {
				dp[i][j] = ((dp[i][j+1] + dp[i-1][j+1] % MOD7)) % MOD7;
			 	if(rock[j] == ROCK[3]) {
			 		res = (res + (dp[i-1][j+1] * v[j] % MOD7)) % MOD7;	
			 	}
			 } else {
			 	dp[i][j] = dp[i][j+1] % MOD7;
			 }
		}
	}
	cout << res;
}

int main() {
	solve();
}
