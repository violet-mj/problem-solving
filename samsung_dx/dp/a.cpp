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

int n, k, vi, ci;
vector<pair<int, int>> v;


void solve(int tn) {
	cin >> n >> k;	
	v.clear();

	for(int i = 0; i < n; i++) {
		cin >> vi >> ci;			
		v.pb(mp(vi, ci));
	}

	int dp[k + 1];

	fill(dp, &dp[k + 1], 0);
	dp[0] = 0;

	for(int i = 0; i < n; i++) {
		int pv = v[i].f;
		int pc = v[i].s;
		for(int j = k; j >= pv; j--) {
			dp[j]	= max(dp[j], dp[j-pv] + pc);
		}
	}

	cout << "#" << tn << " " << dp[k] << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++) solve(i);
}
