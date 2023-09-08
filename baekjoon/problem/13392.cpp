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

const int INF = 1000000000;
int N;
string oldN, newN;

void solve() {
	cin >> N >> oldN >> newN;	
	vector<vector<int>> dp(N + 1, vector<int>(10, INF));
	dp[0][0] = 0;

	for(int i = 0; i < N; i++) {
		for(int j = 0; j < 10; j++)	 {
			if(dp[i][j] == INF)	continue;
			int prevValue = oldN[i] - '0';	
			prevValue = (prevValue + j) % 10;
			int nextValue = newN[i] - '0';
			int diff = nextValue - prevValue;

			if(diff < 0) {
				diff = abs(diff);
				dp[i+1][j] = min(dp[i+1][j], dp[i][j] + diff);
				dp[i+1][(j + 10 - diff) % 10] = min(dp[i+1][(j + 10 - diff) % 10], dp[i][j] + 10 - diff);
			} else {
				dp[i+1][(j + diff) % 10] = min(dp[i+1][(j + diff) % 10], dp[i][j] + diff);
				dp[i+1][j] = min(dp[i+1][j], dp[i][j] + 10 - diff);
			}
		}
	}
	int res = INF;
	for(int i = 0; i < 10; i++) {
		res = min(res, dp[N][i]);
	}
	debug(dp);

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
