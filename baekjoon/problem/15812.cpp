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
#define f first
#define s second
#define endl "\n"
#define all(v) (v).begin(),(v).end()
const int INF = 1 << 30;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
int n, m, cnt;
vector<vector<char>> graph;

int bfs(int fx, int fy, int sx, int sy) {
	int visited[n][m];
	queue<tiii> q;
	int tmpCnt = cnt;
	fill(&visited[0][0], &visited[n-1][m], 0);
	visited[fx][fy] = 1;
	visited[sx][sy] = 1;
	q.push(make_tuple(fx, fy, 1));
	q.push(make_tuple(sx, sy, 1));
	while(!q.empty()) {
		tiii currNode = q.front();
		q.pop();
		int cx = get<0>(currNode);
		int cy = get<1>(currNode);
		int ctime = get<2>(currNode);

		if(tmpCnt <= 0) {
			return ctime;	
		}

		for(int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if(visited[nx][ny]) continue;
			visited[nx][ny] = 1; 
			if(graph[nx][ny] == '1') tmpCnt--;
			q.push(make_tuple(nx, ny, ctime + 1));
		}
	}
	return -1;
}


void solve() {
	cin >> n >> m;
	graph.assign(n, vector<char>(m, '0'));
	cnt = 0;	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> graph[i][j];
			if(graph[i][j] == '1') {
				cnt++;	
			}
		}
	}

	int res = INF;
	for(int i = 0; i < n * m; i++) {
		for(int j = i + 1; j < n * m; j++) {
			int fx = i / m;
			int fy = i % m;
			int sx = j / m;
			int sy = j % m;
			if(graph[fx][fy] == '1' || graph[sx][sy] == '1') continue;
			res = min(res, bfs(fx, fy, sx, sy));
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
