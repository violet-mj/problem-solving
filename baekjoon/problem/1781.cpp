
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
typedef pair<int, lint> pll;

#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl "\n"
#define all(v) (v).begin(),(v).end()

int n, a;
lint b;

void solve() {
	cin >> n;	

	vector<pii> v;

	for(int i = 0; i < n; i++) {
		cin >> a >> b;	
		v.pb(mp(a, b));
	}

	sort(all(v), [] (pii x, pii y){
				return x.f < y.f;
	});
	debug(v);

	int time = 1;
	lint res = 0;

	priority_queue<lint> pq;
	int idx = n - 1;

	for(int i = n; i >= 1; i--) {
		for(;v[idx].first == i && idx>=0;idx--) {
			pq.push(v[idx].second);
		}

		if(!pq.empty()) {
			res += pq.top();
			pq.pop();
		}
	}

	cout << res << "\n";

}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
