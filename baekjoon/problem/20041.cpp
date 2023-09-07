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

int n, x, y;
vector<pii> cops;
pii theft;
vector<int> territory(9, 0);
const map<int, vector<int>> m = {
	{1, {1, 2}},
	{2, {2}},
	{3, {2, 3}},
	{4, {3}},
	{5, {3, 4}},
	{6, {4}},
	{7, {1, 4}},
	{8, {1}} 
};

set<int> ss;


void solve() {
	cin >> n;	
	for(int i = 0; i < n; i++) {
		cin >> x >> y;	
		cops.pb(mp(x, y));
	}
	for(int i = 1; i <= 4; i++) {
		ss.insert(i);
	}
	cin >> x >> y;
	int tx = x;
	int ty = y;
	
	for(pii cop: cops) {
		int copX = cop.f - tx;
		int copY = cop.s - ty;
		if(abs(copX) == abs(copY)) {
			if(copX > 0)	{ 
				if(copY > 0) {
					territory[1] = 1;		
				} else {
					territory[3] = 1;
				}
			} else {
				if(copY > 0) {
					territory[7] = 1;		
				} else {
					territory[5] = 1;
				}
			}
			continue;
		}

		if(abs(copX) > abs(copY)) {
			if(copX > 0)	{
				territory[2] = 1;
			} else {
				territory[6] = 1;	
			}
		} else {
			if(copY > 0)	{
				territory[8] = 1;
			} else {
				territory[4] = 1;	
			}
		}
	}

	debug(territory);

	for(int i = 1; i <= 8; i++){
		if(territory[i]) {
			vector<int> mv = m.at(i);
			for(int mvk: mv) {
				ss.erase(mvk);
			}
		}	
	}

	if(ss.size() == 0) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
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
