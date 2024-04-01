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
	vector<int> v(n);
	set<int> ss;

	vector<int> prefixMex;
	vector<int> res(n);
	for(int i = 0; i < n; i++) {
		cin >> v[i];
		ss.insert(i);
	}
	ss.insert(n);
	res[0] = v[0] == 1 ? 0 : abs(v[0]);
	ss.erase(res[0]);
	prefixMex.pb(*ss.begin());
	debug(ss);

	for(int i = 1; i < n; i++) {
		int prevMex = prefixMex[i - 1];

		// pi == prevMex
		
		ss.erase(prevMex);
		if(v[i] == *ss.begin() - prevMex) {
			res[i] = prevMex; 		
		} else {
			ss.insert(prevMex);
			res[i] = prevMex  - v[i];
			ss.erase(res[i]);
		}
		prefixMex.pb(*ss.begin());
	}
	debug(res, prefixMex);

	for(int i = 0; i < n; i++) {
		cout << res[i] << " \n"[i == n - 1];
	}
}


int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) solve();
}
