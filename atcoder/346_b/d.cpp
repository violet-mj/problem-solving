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
	string s; cin >> s;
	vector<int> v(n);
	for(int i = 0; i < n; i++) cin >> v[i];

	int dp[n + 1][2];
	fill(&dp[0][0], &dp[n][2], 0);

	dp[1][0] = 0;
	dp[1][1] = v[0];

	for(int i = 2; i <= n; i++) {
		int curr = s[i - 1]	- '0';
		int prev = s[i - 2] - '0';

		dp[i][0] = curr ^ prev ? dp[i - 1][0] : dp[i - 1][1];
		dp[i][1] = (curr ^ prev ? dp[i - 1][1] : dp[i - 1][0]) + v[i - 1];
	}

	int init = 1;
	vector<vector<lint>> i1(n + 1, vector<lint>(2, 0));

	for(int i = 1; i <= n; i++) {
		i1[i][0] = init ^ (s[i - 1] - '0') ? v[i - 1] : 0;
		init ^= 1;
	}

	init = 0;
	for(int i = 1; i <= n; i++) {
		i1[i][1] = init ^ (s[i - 1] - '0') ? v[i - 1] : 0;
		init ^= 1;
	}

	for(int i = 1; i <= n; i++) {
		i1[i][0]	+= i1[i - 1][0];
		i1[i][1]	+= i1[i - 1][1];
	}

	lint res1 = 1LL << 60;
	for(int i = 1; i < n; i++) {
		if(i % 2 == 0) {
			res1 = min(res1, i1[i][0] + i1[n][1] - i1[i][1]);
		} else {
			res1 = min(res1, i1[i][1] + i1[n][0] - i1[i][0]);
		}
	}
	for(int i = 1; i < n; i++) {
		if(i % 2 == 1) {
			res1 = min(res1, i1[i][0] + i1[n][1] - i1[i][1]);
		} else {
			res1 = min(res1, i1[i][1] + i1[n][0] - i1[i][0]);
		}
	}

	cout << res1 << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
