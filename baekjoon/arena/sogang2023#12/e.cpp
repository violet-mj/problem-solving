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
	int n;			
	cin >> n;
	vector<int> ti(n+1, 0);
	vector<int> bi(n+1, 0);
	vector<int> ci(n+1, 0);
	vector<lint> dp(n+1, 0);

	for(int i = 1; i <= n; i++) cin >> ti[i];
	for(int i = 1; i <= n; i++) cin >> bi[i];
	for(int i = 1; i <= n; i++) cin >> ci[i];
	vector<vector<int>> vi(n + 1, vector<int>());
	for(int i = 1; i <= n; i++) {
		vi[i] = {ti[i], bi[i], ci[i]};
	}

	auto bs = [&](lint v) {
		int l = 0, r = n + 1;			
		while(l + 1 < r) {
			int mid = (l + r) >> 1;	
			if(ti[mid] >= v) {
				r = mid;	
			} else {
				l = mid;	
			}
		}

		return l;
	};

	for(int i = 1; i <= n; i++) {
		int lo = bs(ti[i] - bi[i]);
		dp[i] = max(dp[i - 1], dp[lo] + ci[i]);
	}

	cout << dp[n] << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
