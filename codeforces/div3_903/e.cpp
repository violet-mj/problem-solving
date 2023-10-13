#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <utility>

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

const int INF = 1e9;

void solve() {
	int n; 
	cin >> n;

	vector<int> value(n, 0);

	for(int i = 0; i < n; i++) cin >> value[i];

	vector<int> dp(n+1, 0);
	for(int i = 0; i < n+1; i++) {
		dp[i] = i;	
	}

	for(int i = 0; i < n; i++) {
		if(i != 0) {
			dp[i] = min(dp[i-1] + 1, dp[i]);
		}

		if(i+value[i]+1 <= n) {
			dp[i+value[i]+1] = min(dp[i], dp[i+value[i]+1]);
		}
	}

	debug(dp);

	cout << min(dp[n], dp[n-1] + 1)<< "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) solve();
}
