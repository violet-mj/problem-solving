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
int n, m, cmd, l, r, k, x;
vector<lint> values;
vector<lint> fenwick;


void update(int i, int diff) {
	while(i <= n) {
		fenwick[i] += diff;	
		i += (i & -i);
	}
}

lint sum(lint i) {
	lint ans = 0;
	while(i > 0) {
		ans += fenwick[i];
		i -= (i & -i);
	}
	return ans;
}

void solve() {
	cin >> n;			
	values.resize(n+2,0);
	fenwick.resize(n+2, 0);
	for(int i = 1; i <= n; i++) cin >> values[i];
	cin >> m;
	for(int i = 0; i < m; i++) {
		cin >> cmd;	
		if(cmd == 1) {
			cin >> l >> r >> k;
			update(l, k);
			update(r+1, -k);
		} else {
			cin >> x;	
			lint diff = sum(x);
			cout << values[x] + diff << "\n";
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
