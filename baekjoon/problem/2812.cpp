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

struct tmp {
	bool operator() (pii p1, pii p2) {
		if(p1.f == p2.f) {
			return p1.s > p2.s;
		}
		return p1.f < p2.f;
	}
};

void solve() {
	int n, k; string s; 
	cin >> n >> k >> s;
	vector<char> stk;
	stk.pb(s[0]);
	int kk = k;
	
	for(int i = 1; i < n; i++) {
		while(!stk.empty() && (s[i] > stk.back()) && k > 0) {
			stk.pop_back();	
			k--;
		}
		stk.pb(s[i]);
	}

	for(int i = 0; i < n - kk; i++) {
		cout << stk[i];
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
