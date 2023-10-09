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

void solve() {
	int n;		
	cin >> n;
	vector<int> player(n+1, 0);
	vector<vector<char>> k(n+1, vector<char>(n+1, '-'));

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++){
			cin >> k[i][j];
		}
	}

	for(int i = 1; i <= n; i++) {
		for(int j = i+1; j <= n; j++)	 {
			if(k[i][j] == 'o')		 {
				player[i]++;
			} else {
				player[j]++;	
			}
		}
	}
	debug(player);
	vector<pii> ans;

	for(int i = 1; i <= n; i++) {
		ans.pb(mp(i, player[i]));
	}

	sort(all(ans), [](pii p1, pii p2) {
		if(p1.s == p2.s) {
			return p1.f < p2.f;	
		}					
		return p1.s > p2.s;
	});

	for(int i = 0; i < n; i++){
		cout << ans[i].f << " \n"[i == n - 1];
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
