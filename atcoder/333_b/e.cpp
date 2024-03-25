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
	vector<pii> state(n);

	vector<int> monster(n+1, 0);
	vector<int> potion(n + 1, 0);
	int pick = 0;
	for(int i = 0; i < n; i++) {
		cin >> state[i].f >> state[i].s;	
		if(state[i].f == 1) pick++;		
	}

	vector<int> picks(pick, 0);
	int pcnt = pick - 1;
	int max_ = 0;
	int kcnt = 0;
	for(int i = n - 1; i >= 0; i--) {
		debug(monster);
		auto [ti, xi]	= state[i];
		if(ti == 1) {
			if(monster[xi] > 0) {
				debug(xi, 1);
				monster[xi]--;		
				picks[pcnt--] = 1;
				kcnt++;
			} else {
				pcnt--;
			}
		} else {
			monster[xi]++;
			kcnt--;
		}
	}

	if(kcnt != 0) {
		cout << -1 << "\n";
		return;
	}

	pcnt = 0;
	int tmp = 0;
	for(int i = 0; i < n; i++) {
		auto [ti, xi]	= state[i];
		debug(tmp);
		if(ti == 1) {
			if(picks[pcnt++] == 1) {
				tmp++;	
				max_ = max(max_, tmp);
			}
		} else {
			tmp--;
		}
	}

	cout << max_ << "\n";

	for(int i = 0; i < picks.size(); i++) {
		cout << picks[i] << " ";
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
