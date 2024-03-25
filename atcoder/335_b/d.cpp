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

const int dx[4] = {0, -1, 0, 1};
const int dy[4] = {1, 0, -1, 0};

void solve() {
	int n; cin >> n;		
	int currdir = 0;	
	int curr = 1;

	int dp[n][n];
	fill(&dp[0][0], &dp[n-1][n], -1);
	dp[0][0] = 1;
	int mid = (n + 1) / 2 - 1;
	dp[mid][mid] = -2;
	int currx = 0; 
	int curry = 0;
	
	while(1) {

		if(dp[currx][curry] == n * n - 1) break;

		int nx = currx + dx[currdir];
		int ny = curry + dy[currdir];

		if(nx < 0 || nx >= n || ny < 0 || ny >= n) {
			currdir = (currdir + 1) % 4;	
			continue;
		}

		if(dp[nx][ny] != -1) {
			currdir	= (currdir + 1) % 4;
			continue;
		}

		if(dp[nx][ny] == -2) {
			break;	
		}

		dp[nx][ny] = ++curr;
		currx = nx;
		curry = ny;
	}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++)	{
			if(dp[i][j] == -2) {
				cout << 'T' << " ";	
			} else {
				cout << dp[i][j] << " ";
			}
		}
		cout << "\n";
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
