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
	vector<int> check(4, 0);
	for(int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;	
		if(x < 0) {
			check[0] |= 1;	
		} else if(x > 0) {
			check[2] |= 1;	
		}

		if(y < 0) {
			check[3] |= 1;	
		} else if(y > 0) {
			check[1] |= 1;	
		} else {
			continue;	
		}
	}
	debug(check);
	bool flag = true;

	for(int i = 0; i < 4; i++) {
		if(check[i] == 0)	 {
			flag = false;	
		}
	}

	cout << (flag ? "NO" : "YES") << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) solve();
}
