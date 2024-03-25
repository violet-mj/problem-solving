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
	int n, m, x; cin >> n >> m >> x;
	vector<vector<int>> dp(m + 1, vector<int>(n, 0));
	x--;
	dp[0][x] = 1;

	for(int i = 0; i < m; i++) {
		int ri; char cmd;
		cin >> ri >> cmd;

		if(cmd == '0') {
			for(int j = 0; j < n; j++) {
				if(dp[i][j] == 0) continue;
				dp[i + 1][(j + ri) % n] = 1;
			}
		} else if(cmd == '1') {
			for(int j = 0; j < n; j++) {
				if(dp[i][j] == 0) continue;
				dp[i + 1][(j - ri + n) % n] = 1;
			}
		} else {
			for(int j = 0; j < n; j++) {
				if(dp[i][j] == 0) continue;
				dp[i + 1][(j + ri) % n] = 1;
				dp[i + 1][(j - ri + n) % n] = 1;
			}
		}
	}

	vector<int> res;

	for(int i = 0; i < n; i++) {
		if(dp[m][i] == 1)	 {
			res.pb(i + 1);
		}
	}
	cout << res.size() << "\n";
	for(int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
	cout << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) solve();
}
