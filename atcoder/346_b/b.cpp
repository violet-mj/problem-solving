
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
	int w, b; cin >> w >> b;		
	string s = "wbwbwwbwbwbw";

	for(int i = 0; i < 200; i++) {
		for(int j = i; j < 200; j++)	 {
			int cw = 0;
			int cb = 0;

			for(int z = i; z <= j; z++) {
				s[z % s.size()]	== 'b' ? cb++ : cw++;
			}

			if(cw == w && cb == b) {
				cout << "Yes\n";
				return;
			}
		}
	}
	cout << "No\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
