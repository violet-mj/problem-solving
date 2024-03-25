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

const int dx[5] = {0, 1, 0, -1, 0};
const int dy[5] = {1, 0, -1, 0, 0};

void solve() {		
	int n, m;
	cin >> n >> m;
	int sx, sy, ex, ey;
	cin >> sx >> sy >> ex >> ey;
	vector<vector<vector<char>>> graph(4, vector<vector<char>>(n, vector<char>(m)));
// auto printArray = [&](int num) {
// for(int i = 0; i < n; i++)	 {
// for(int j = 0; j < m; j++)	{
// cout << graph[num][i][j] << " ";
// }
// cout << "\n";
// }
// };

	vector<vector<int>> ghost;
	set<char> digit = {'0', '1', '2', '3'};

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> graph[0][i][j];
			if(digit.find(graph[0][i][j]) != digit.end()) {
				ghost.pb({i, j, graph[0][i][j] - '0'});
			}
		}
	}

	for(int i = 1; i < 4; i++) {
		for(int x = 0; x < n; x++) {
			for(int y = 0; y < m; y++)	 {
				graph[i][x][y] = graph[0][x][y];
			}
		}
	}

	for(int i = 0; i < 4; i++) {
		for(vector<int> currGhost: ghost)	{
			int currDir = (currGhost[2] + i) % 4;
			int ddx = dx[currDir];
			int ddy = dy[currDir];
			int currX = currGhost[0];
			int currY = currGhost[1];
			graph[i][currX][currY] = 'L';
			while(1) {
				int nx = currX + ddx;
				int ny = currY + ddy;
			  if(nx < 0 || nx >= n || ny < 0 || ny >= m) break;
				if(graph[i][nx][ny] == '#')	break;
				graph[i][nx][ny] = 'L';
				currX = nx;
				currY = ny;
			}
		}
	}

	vector<vector<vector<int>>> visited(4, vector<vector<int>>(n, vector<int>(m, 0)));

	// for(int i = 0; i < 4; i++) {
		// for(int j = 0; j < n; j++)	 {
			// for(int z = 0; z < m; z++) {
				// cout << graph[i][j][z] << " ";
			// }
			// cout << "\n";
		// }
		// cout << "\n";
	// }
	queue<vector<lint>> q;
	q.push({sx-1, sy-1, 0LL});
	visited[0][sx-1][sy-1] = 1;

	while(!q.empty()) {
		vector<lint> currNode = q.front();
		q.pop();
		int cx = currNode[0];
		int cy = currNode[1];
		lint ctime = currNode[2];
		int time = (ctime + 1) % 4;

		if(cx == ex - 1 && cy == ey - 1) {
			cout << ctime << "\n";
			return;
		}

		for(int i = 0; i < 5; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if(graph[time][nx][ny] == 'L') continue;
			if(graph[time][nx][ny] == '#') continue;
			if(visited[time][nx][ny] == 1) continue;
			visited[time][nx][ny] = 1;
			q.push({nx, ny, ctime + 1});
		}
	}
	cout << "GG\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
