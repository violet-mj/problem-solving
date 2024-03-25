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
 
	for(int i = 0; i < n; i++) {
		priority_queue<pll, vector<pll>, tmp> pq;	
		pq.push(mp(1, 0));
 
		for(int j = 1; j <= min(m - 1, d + 1); j++) {
			dp[i][j] = sea[i][j] + 2LL;
			pq.push(mp(dp[i][j], j));
		}
 
		for(int j = d + 2; j < m; j++) {
			pll curr;
			while(1) {
				curr = pq.top();
				if(j - curr.s - 1LL <= d) {
					if(j == m - 1 && curr.s == 0) {
						pq.pop();
						continue;
					}
					break;
				} else {
					pq.pop();	
				}
			}
			dp[i][j] = curr.f + sea[i][j] + 1LL;
			pq.push(mp(dp[i][j], j));
		}
	}
 
	lint cnt = 0LL;
	lint res; 
 
	for(int i = 0; i < k; i++) {
		cnt += dp[i][m - 1];
	}
	res = cnt;
 
	for(int i = k; i < n; i++) {
		cnt -= dp[i-k][m-1];
		cnt += dp[i][m-1];
		res = min(res, cnt);
	}
 
	debug(dp);
 
	cout << res <<"\n";
 
}
 
int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) solve();
}
