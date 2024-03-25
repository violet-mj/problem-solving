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
	int n, q;		
	cin >> n;
	vector<int> sudo(n);
	vector<int> swi(n, 1);
	lint init = 0;
	for(int i = 0; i < n; i++) {
		cin >> sudo[i];
		init += sudo[i];
	}
	cin >> q;
	int cmd;
	cout << init << "\n";
	for(int i = 0; i < q; i++) {
		cin >> cmd;	
		if(cmd == 1) {
			int i1, i2; cin >> i1 >> i2;
			if(swi[i1-1]) init += i2 - sudo[i1-1];
			sudo[i1-1] = i2;
		} else {
			int i1; cin >> i1;
			if(swi[i1-1]) {
				init -= sudo[i1-1];
			} else {
				init += sudo[i1-1];
			}
			swi[i1-1] ^= 1;
		}
		cout << init << "\n";
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
