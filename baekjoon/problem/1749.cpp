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
	int n, m;		
	cin >> n >> m;
	vector<vector<int>> graph(n+1, vector<int>(m+1, 0));
	vector<vector<int>> prefix2D(n+1, vector<int>(m+1, 0));

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++)	{
			cin >> graph[i][j];	
		}
	}

	for(int i =1; i <= n; i++) {
		for(int j = 1; j <= m; j++)	{
			prefix2D[i][j] = prefix2D[i-1][j] + prefix2D[i][j-1] - prefix2D[i-1][j-1] + graph[i][j];
		}
	}

	int res = -INF;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++)		 {
			for(int x = 1; x <= n; x++)	 {
				for(int y = 1; y <= m; y++)	 {
					int nextX = x+i;
					int nextY = y+j;
					int prevX = x-1;
					int prevY = y-1;
					if(nextX > n || nextY > m) continue;
					int value = prefix2D[nextX][nextY] - prefix2D[prevX][nextY] - prefix2D[nextX][prevY] + prefix2D[prevX][prevY];
					res = max(res, value);
				}
			}
		}
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
