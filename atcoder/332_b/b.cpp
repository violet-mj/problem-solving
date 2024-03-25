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
	int k, g, m;		
	cin >> k >> g >> m;
	debug(k ,g);
	int gg = 0;
	int mm = 0;

	for(int i = 0; i < k; i++) {
		if(gg == g) {
			gg = 0;	
		} else if(mm == 0) {
			mm = m;	
		} else {
			int ggk = gg;
			gg = min(g, gg + mm);
			int diffg = gg - ggk;
			mm = mm - diffg;
		}
		debug(gg, mm);
	}

	cout << gg << " " << mm;
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
