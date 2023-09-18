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
typedef tuple<int,int,int> tiii; 

#define pb push_back
#define mp make_pair
#define mt make_tuple
#define f first
#define s second
#define endl "\n"
#define all(v) (v).begin(),(v).end()

int N, K;
const int INF = 1e9;
void solve() {
	cin >> N >> K;	
	vector<pii> coords(N);
	vector<vector<int>> dist(N, vector<int>(N, INF));
	vector<vector<int>> dp(N+1, vector<int>(N, INF));
	dp[1][0] = 0;

	for(int i = 0; i < N; i++) {
		cin >> coords[i].f >> coords[i].s;
		dist[i][i] = 0;
	}

	for(int i = 0; i < N; i++) {
		for(int j = i+1; j < N; j++) {
			dist[i][j] = abs(coords[i].f - coords[j].f) + abs(coords[i].s - coords[j].s);
		}
	}

	for(int i = 0; i < N; i++) {
		for(int j = i+1; j < N; j++)	 {
			for(int z = 1; z < N; z++)	 {
				dp[z+1][j] = min(dp[z+1][j], dp[z][i] + dist[i][j]);
			}
		}
	}
	debug(dp);
	int res = INF;
	for(int i = N-K; i <= N; i++) {
		res = min(res, dp[i][N-1]);
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
