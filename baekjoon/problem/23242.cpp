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

int B, N;
const ld INF = 1000000000;

void solve() {
	cin >> B >> N;	

	vector<int> values(N + 1, 0);

	for(int i = 1; i <= N; i++) {
		cin >> values[i];
	}

	vector<vector<int>> dp(31, vector<int>(N + 1, INF));
	dp[0][0] = 0;

	for(int i = 1; i <= N; i++) {
		for
		for(int j = 0; j < B; j++)	 {
			if(dp[j][i] == INF)	continue;
			
		}
	}


	
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
