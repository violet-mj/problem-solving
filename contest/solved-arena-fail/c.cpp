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
	lint n;		
	cin >> n;
	vector<lint> v(n+1, 0LL);
	vector<lint> pre(n+1, 0LL);
	map<lint, lint> count;

	for(int i = 1; i <= n; i++) {
		cin >> v[i];
	}

	debug(v);
	sort(all(v));
	debug(v);

	for(int i = 1; i <= n; i++) {
		pre[i] = pre[i-1] + v[i];
		if(i < n - 1) {
			count[v[i]]++;
		}
	}

	lint res = 0LL;

	if(pre[n-3] == v[n-2]) res++;
	
	res += count[pre[n-2] - v[n-1]];
	debug(pre[n-2] - v[n-1], count[pre[n-2] - v[n-1]], res);

	lint init = pre[n-1] - v[n];
	debug(init);
	lint cnt1 = 0;
	lint cnt2 = 0;
	count[v[n-1]]++;

	for(auto i = count.begin(); i != count.end(); i++) {
		lint currv = i->first;	
		lint currc = i->second;
		lint otherv = init - currv;
		if(init - currv != currv) {
			cnt1 += currc * count[otherv];
		} else {
			cnt2 += currc * (currc - 1LL) / 2;
		}
		debug(currv, currc, otherv, count[otherv], cnt1, cnt2);
	}
	cnt1/=2;


	cout << res + cnt1 + cnt2<< "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
