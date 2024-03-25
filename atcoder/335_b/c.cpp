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



map<char, pii> mm;

void solve() {
	
	int n, q;
	cin >> n >> q;

	mm['U'] = mp(0, 1);
	mm['D'] = mp(0, -1);
	mm['R'] = mp(1, 0);
	mm['L'] = mp(-1, 0);

	vector<pii> dq;

	for(int i = n; i >= 1; i--) {
		dq.push_back(mp(i, 0));
	}

	int curr = n - 1;
	int init = 0;

	for(int i = 0; i < q; i++) {
		int cmd; cin >> cmd;	
		if(cmd == 1) {
			char dir; cin >> dir;
			dq.push_back(mp(dq[curr].f + mm[dir].f, dq[curr].s + mm[dir].s));
			curr++;
			dq[init++] = mp(-1, -1);
		} else {
			int idx; cin >> idx;	
			pii res = dq[curr - idx + 1];
			cout << res.f << " " << res.s << "\n";
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
