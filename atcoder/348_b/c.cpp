
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
	vector<pii> p(n);
	map<int, int> m;
	for(int i = 0; i < n; i++) {
		cin >> p[i].f >> p[i].s;	
		m[p[i].s] = p[i].f;
	}

	for(int i = 0; i < n; i++) {
		m[p[i].s] = min(m[p[i].s], p[i].f);
	}

	int max_ = -1;

	for(auto i = m.begin(); i != m.end(); i++) {
		max_ = max(max_, i->s);
	}

	cout << max_ << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
