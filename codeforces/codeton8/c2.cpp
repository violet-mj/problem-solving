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
	int n, x, y;
	cin >> n >> x >> y;
	vector<int> v(x);
	for(int i = 0; i < x; i++) cin >> v[i];
	sort(all(v));

	int res = x - 2;

	debug(v);

	vector<vector<int>> check(2);


	for(int i = 1; i < x; i++) {
		if(v[i] - v[i - 1] > 2) {
	 		check[(v[i] - v[i - 1]) % 2].pb(v[i] - v[i - 1]);
	 	}
	 	if(v[i] - v[i - 1] == 2)	 {
	 		debug(i);
	 		res++;	
	 	}
	}

	if(n + v[0] - v[x - 1] > 2) {
	 	check[(n + v[0] - v[x - 1]) % 2].pb(n + v[0] - v[x - 1]);
	}
	if(n + v[0] - v[x - 1] == 2) {
		res++;		
	}


	int used = 0;
	int add = 0;
	int tmpY = y;

	sort(all(check[0]));
	sort(all(check[1]));
	int cs = check[0].size();

	int evenCnt = 0;

	for(int i = 0; i < cs; i++) {
		int usee = (check[0][i] - 2) / 2;
		if(usee <= y) {
			evenCnt += usee * 2 + 1;
			y -= (check[0][i] - 2) / 2;
		} else {
			evenCnt += y * 2;
			y = 0;
		}
	}

	int ns = check[1].size();
	int oddCnt = 0;

	for(int i = 0; i < ns; i++) {
		int use = check[1][i] / 2;
		if(use <= y) {
			oddCnt+= 2 * use;	
			y -= use;
		} else {
			oddCnt+= 2 * y;
			y = 0;
		}
	}

	debug(evenCnt, oddCnt, used, res, add);
	debug(check[0]);
	debug(check[1]);

	cout << oddCnt + evenCnt + res << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) solve();
}
