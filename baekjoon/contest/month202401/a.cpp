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

map<char, pii> m = {
	{'U', {1, 0}},
	{'D', {-1, 0}},
	{'L', {0, -1}},
	{'R', {0, 1}}
};

void solve() {
	int currx = 0;
	int curry = 0;

	int n, k; string s;cin >> n >> k >> s;

	for(int i = 0; i < s.size() * min(k, 10000); i++) {
		char currs = s[i % s.size()];
		pii currd = m[currs];
		currx += currd.f;
		curry += currd.s;

		if(currx == 0 && curry == 0) {
			cout << "YES";
			return;
		}
	}

	cout << "NO";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
