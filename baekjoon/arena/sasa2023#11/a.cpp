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
	int n, q, cmd, a, b, c;				
	cin >> n;
	vector<int> values(n);
	for(int i = 0; i < n; i++) cin >> values[i];
	cin >> q;

	for(int i =0 ;i < q ; i++) {
		cin >> cmd >> a >> b;


		if(cmd == 1) {
			cin >> c;
			int cnt = 0;
			for(int i = a - 1; i < b; i++) {
				if(values[i] == c)	cnt++;
			}
			cout << cnt << "\n";
		} else {
			for(int i = a - 1; i < b; i++) {
				values[i] = 0;
			}
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
