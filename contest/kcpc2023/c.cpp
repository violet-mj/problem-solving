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
	int n, m;		
	cin >> n >> m;

	vector<vector<char>> g1(n, vector<char>(m));
	vector<vector<char>> g2(n, vector<char>(m));
	vector<vector<int>> visited(n, vector<int>(m, 0));

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> g1[i][j];
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> g2[i][j];
		}
	}

	auto bfs = [&](pii currCoord) {
		vector<pii> coords;
		queue<pii> q;
		visited[currCoord.f][currCoord.s] = 1;
		q.push(currCoord);
		coords.pb(currCoord);
		char iColor = g1[currCoord.f][currCoord.s];

		while(!q.empty()) {
			pii coord = q.front();	
			q.pop();
			for(int i = 0; i < 4; i++) {
				int nx = coord.f + dx[i];
				int ny = coord.s + dy[i];
				if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
				if(visited[nx][ny]) continue;
				if(iColor != g1[nx][ny]) continue;
				q.push(mp(nx, ny));
				coords.pb(mp(nx, ny));
				visited[nx][ny] = 1;
			}
		}

		return coords;
	};


	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++)	 {
			if(!visited[i][j]) {
				vector<pii> coords = bfs(mp(i, j));
				char currColor = g2[coords[0].f][coords[0].s];

				for(int i = 1; i < coords.size(); i++) {
					if(currColor != g2[coords[i].f][coords[i].s]) {
						cout << "NO\n";
						return;
					}
				}
			}
		}
	}

	cout << "YES\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
