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
	int n; cin >> n;
	vector<lint> val(n);
	for(int i = 0; i < n; i++) cin >> val[i];
	lint bit[n][30];
	lint dp[n][30];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 30; j++)	 {
			bit[i][j] = (val[i] >> j) & 1;
		}
	}

	lint res = 0LL;

	for(lint j = 0; j < 30; j++) {
		for(lint i = 0; i < n; i++)	 {
			if(i == 0)	 {
				dp[i][j] = bit[i][j];
				continue;
			}
			dp[i][j] = dp[i-1][j] + bit[i][j];
		}

		lint parity[2] = {0LL, 0LL};

		for(int i = 0; i < n; i++) {
			parity[dp[i][j] % 2]++;
		}

		res += (parity[0] * parity[1] + parity[1]) * (1LL << j);
	}
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
