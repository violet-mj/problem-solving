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

int I, N, K;
string INK, CMD;
map<char, pii>  dir = {
	{'R', mp(0, 1)},
	{'L', mp(0, -1)},
	{'D', mp(1, 0)},
	{'U', mp(-1, 0)},
};

void solve() {
	cin >> I >> N >> K >> INK;
	vector<vector<char>> maps(N, vector<char>(N, '.')); 
	vector<vector<char>> colors(N, vector<char>(N, '.')); 
	pii currSquare;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			cin >> maps[i][j];
			if(maps[i][j] == '#') {
				colors[i][j] = maps[i][j];
			}
			if(maps[i][j] == '@') {
				currSquare = mp(i, j);
			}
		}
	}
	cin >> CMD;

	int inkAmount = 0;
	int inkColor = -1;

	for(int i = 0; i < CMD.size(); i++) {
		char cmd = CMD[i];
		if(cmd == 'j') {
			inkAmount++;	
		} else if(cmd == 'J') {
			auto [cx, cy] = currSquare;
			inkColor++;	
			for(int i = 0; i < N; i++)  {
				for(int j = 0; j < N; j++)	 {
					int dist = abs(i - cx) + abs(j - cy);	
					if(dist <= inkAmount && maps[i][j] == '#') {
						colors[i][j] = INK[inkColor % I];
					}
				}
			}
			inkAmount = 0;
		} else {
			int nx = currSquare.f + dir[cmd].f;
			int ny = currSquare.s + dir[cmd].s;
			if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			if(maps[nx][ny] == '#') continue;
			currSquare.f = nx;
			currSquare.s = ny;
		}
	}

	colors[currSquare.f][currSquare.s] = '@';

	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			cout << colors[i][j];
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
