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

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

void solve() {
	int n, m, x1, y1, x2, y2;		
	cin >> n >> m >> x1 >> y1 >> x2 >> y2;
	x1--;y1--;x2--;y2--;
	debug(x1,y1,x2,y2);
	vector<string> board(n);
	int visited[n][m];
	fill(&visited[0][0], &visited[n-1][m], 0);
	for(int i = 0; i < n; i++) cin >> board[i];

	deque<vector<int>> q;

	q.push_back({x1, y1, 0, 0});
	visited[x1][y1] = 0;

	while(!q.empty()) {
		vector<int> curr = q.front();	
		q.pop_front();

		int cx = curr[0];
		int cy = curr[1];
		int th = curr[2];
		int cdist = curr[3];
		debug(cx, cy);

		if(board[cx][cy] == '#') {
			cout << th + 1 << "\n";
			return;
		}

		for(int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if(visited[nx][ny]) continue;
			if(board[nx][ny] == '1') {
				q.push_back({nx, ny, th + 1, cdist + 1});
			} else {
				q.push_front({nx, ny, th, cdist + 1});
			}
			visited[nx][ny] = 1;
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
