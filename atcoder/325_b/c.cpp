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

const int dx[8] = {-1,-1,-1,0,1,1,1,0};
const int dy[8] = {-1, 0, 1, 1, 1, 0, -1,-1};

void solve() {
	int h, w;
	cin >> h >> w;

	vector<vector<char>> graph(h, vector<char>(w));

	for(int i=0; i<h; i++) {
		for(int j=0; j<w; j++)	 {
			cin >> graph[i][j];
		}
	}

	vector<vector<int>> visited(h, vector<int>(w, 0));


	auto bfs = [&](int x, int y) {
		queue<vector<int>>q;
		visited[x][y] = 1;
		q.push({x, y});

		while(!q.empty()) {
			vector<int> curr = q.front();	
			q.pop();
			int currX = curr[0];
			int currY = curr[1];
			for(int i = 0; i < 8; i++) {
				int nx = currX + dx[i];	
				int ny = currY + dy[i];
				if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
				if(graph[nx][ny] == '.' || visited[nx][ny]) continue;
				visited[nx][ny] = 1;
				q.push({nx, ny});
			}
		}
	};

	int res = 0;

	for(int i = 0; i < h; i++) {
		for(int j = 0; j < w; j++) {
			if(!visited[i][j] && graph[i][j] == '#')	 {
				bfs(i, j)	;
				res++;
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
