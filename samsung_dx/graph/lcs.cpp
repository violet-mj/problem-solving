
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

int t;
string f, s;

void solve() {
	cin >> f >> s;

	int fl = f.size();
	int sl = s.size();

	int dp[fl+1][sl+1];
	fill(&dp[0][0], &dp[fl][sl+1], 0);

	for(int i = 1; i <= fl; i++) {
		for(int j = 1; j <= sl; j++) {
			if(f[i-1] == s[j-1]) {
				dp[i][j] = max(dp[i-1][j-1] + 1, dp[i][j-1]);
			} else {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}

	cout << dp[fl][sl] << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	solve();
}
