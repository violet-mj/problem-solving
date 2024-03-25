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

struct tmp {
	bool operator()(pll p1, pll p2) {
		if(p1.f == p2.f) {
			return p1.s < p2.s;
		}
		return p1.f > p2.f;	
	}
};

void solve() {
	lint n, m, k, d; cin >> n >> m >> k >> d;
	vector<vector<lint>> dp(n, vector<lint>(m, 0LL));
	vector<vector<lint>> sea(n, vector<lint>(m, 0LL));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> sea[i][j];
		}
	}

	debug(sea);

	for(int i = 0; i < n; i++) {
		dp[i][0] = 1LL;
	}

	vector<lint> res;

	for(int i = 0; i < n; i++) {
		multiset<lint> ms;
		ms.insert(dp[i][0]);

		for(int j = 1; j < m; j++) {
			dp[i][j] = *ms.begin() + sea[i][j] + 1;
			if(j >= d + 1) {
				ms.erase(ms.find(dp[i][j - d - 1]));
			}
			ms.insert(dp[i][j]);
		}

		res.pb(dp[i][m - 1]);
	}

	vector<lint> pre;
	pre.pb(res[0]);
	for(int i = 1; i < n; i++) {
		pre.pb(pre[i - 1] + res[i]);
	}

	debug();
	lint cnt = 1LL << 60;

	for(int i = k - 1; i < n; i++) {
		if(i == k - 1)			 {
			cnt = min(cnt, pre[i]);
		} else {
			cnt = min(cnt, pre[i] - pre[i - k]);
		}
	}

	cout << cnt << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) solve();
}
