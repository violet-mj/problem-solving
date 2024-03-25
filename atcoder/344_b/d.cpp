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
	string T; cin >> T;		
	int n; cin >> n;
	vector<vector<string>> bags(n + 1);
	for(int i = 1; i <= n; i++) {
		int Ai; cin >> Ai;	
		for(int j = 0; j < Ai; j++) {
			string tmp; cin >> tmp;	
			bags[i].pb(tmp);
		}
	}

	vector<vector<int>> dp(n + 1, vector<int>(T.size() + 1, 1 << 30));
	dp[0][0] = 0;

	for(int i = 1; i <= n; i++) {
		for(int k = 0; k <= T.size(); k++) {
			dp[i][k] = dp[i - 1][k];
		}
		for(int j = 0; j < bags[i].size(); j++)	 {
			int ss = bags[i][j].size();
			string curr = bags[i][j];
			for(int z = 1; z <= T.size(); z++) {
				bool flag = true;
				for(int zz = 0; zz < ss; zz++) {
					if(T[z + zz - 1] != curr[zz] || z + zz - 1 >= T.size()) {
						flag = false;	
						break;
					}
				}
				if(!flag) continue;
				dp[i][z + ss - 1] = min(dp[i][z + ss - 1], dp[i - 1][z - 1] + 1);
 			}
		}
	}

	debug(dp);

	int res = 1 << 30;

	for(int i = n; i >= 1; i--) {
		if(dp[i][T.size()] != 1 << 30)	 {
			res = min(res, dp[i][T.size()]);
		}
	}
	cout << (res == 1 << 30 ? -1 : res) << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
