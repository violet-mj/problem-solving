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

void solve() {
	int m, n, b; cin >> m >> n >> b;		
	int gr[n][m];

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> gr[i][j];
		}
	}

	int tTime = 1 << 30;
	int height = -1;


	for(int i = 0; i <= 256; i++) {
		int c[2] = {0, 0};
		int time = 0;
		for(int x = 0; x < n; x++) {
			for(int y = 0; y < m; y++) {
				c[(- i + gr[x][y]) > 0]	+= abs(i - gr[x][y]);
			}
		}
		int inven = b + c[1];
		time += 2 * c[1];
		if(c[0] > inven) continue;
		time += c[0];

		if(time <= tTime) {
			tTime = time;	
			height = i;
		}
	}
	cout << tTime << " " << height << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
