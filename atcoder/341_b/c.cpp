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

map<char, pii> dir = {
	{'L', {0, -1}},
	{'R', {0, 1}},
	{'U', {-1, 0}},
	{'D', {1, 0}},
};

void solve() {
	int h, w, n;
	string cmd;
	cin >> h >> w >> n >> cmd;
	vector<string> graph(h);
	for(int i = 0; i < h; i++) cin >> graph[i];
	int cnt = 0;

	for(int i= 1; i < h - 1; i++) {
		for(int j = 1; j < w - 1; j++) {
			bool flag = true;
			if(graph[i][j] == '#') continue;
			int currx = i;
			int curry = j;
			for(int z = 0; z < cmd.size(); z++) {
				currx += dir[cmd[z]].f;
				curry += dir[cmd[z]].s;
				if(graph[currx][curry] == '#') {
						flag = false;	
						break;
				}
			}
			if(flag) cnt++;
		}
	}

	cout << cnt;
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
