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
	int n, x, y; cin >> n >> x >> y;			
	vector<int> v(x);
	for(int i = 0; i < x; i++) cin >> v[i];
	sort(all(v));

	int res = x - 2;

	debug(v);

	for(int i = 1; i < x; i++) {
		if(v[i] - v[i - 1] == 2)	 {
			debug(i);
			res++;	
		}
	}

	if(n + v[0] - v[x - 1] == 2) {
		res++;		
	}

	cout << res << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) solve();
}
