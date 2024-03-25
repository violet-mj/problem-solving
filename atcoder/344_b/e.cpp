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
	int n; cin >> n;		
	vector<int> v(n);
	for(int i = 0; i < n; i++) {
		cin >> v[i];
	}

	map<int, int> dir;
	map<int, int> rdir;

	int init = v[0];
	int last = v[n - 1];

	for(int i = 0; i < n - 1; i++) {
		dir[v[i]]	= v[i + 1];
	}

	for(int i = n - 1; i >= 1; i--) {
		rdir[v[i]]	= v[i - 1];
	}

	int q; cin >> q;
	for(int i = 0; i < q; i++) {
		int cmd; cin >> cmd;	
		if(cmd == 1) {
			int curr, value; cin >> curr >> value;	
			if(curr == last) {
				dir[curr]	= value;
				rdir[value] = curr;
				last = value;
			} else {
				int nxt = dir[curr];
				dir[curr] = value;
				dir[value] = nxt;
				rdir[nxt] = value;
				rdir[value] = curr;
			} 
		} else {
				int curr; cin >> curr;
				if(curr == init) {
					int nxt = dir[curr];
					init = dir[curr];
					dir.erase(curr);
					rdir.erase(nxt);
				} else if(curr == last) {
					int prv = rdir[curr];
					last = prv;
					rdir.erase(curr);
					dir.erase(prv);
				}	else {
					int nxt = dir[curr];
					int prv = rdir[curr];
					dir.erase(curr);
					rdir.erase(curr);
					dir[prv] = nxt;
					rdir[nxt] = prv;
				}
		}
		debug(cmd, init, dir);
	}

	cout << init << " ";
	while(dir.find(init) != dir.end()) {
		cout << dir[init] << " ";
		init = dir[init];
	}
	cout << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
