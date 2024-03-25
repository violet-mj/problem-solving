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

lint cnt = 0LL;
map<lint, lint> m;

lint check(lint val) {
	if(val <= 1LL) return 0LL;
	if(m.find(val) != m.end()) {
		return m[val];
	}
	m[val] = check((val + 1LL) / 2LL) + check(val / 2LL) + val;
	return m[val];
}

void solve() {
	lint n;		
	cin >> n;
	check(n);
	cout << m[n] << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
