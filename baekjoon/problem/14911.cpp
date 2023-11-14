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
	vector<int> k;		
	int tmp;
	while(!cin.eof()) {
		cin >> tmp;
		k.pb(tmp);
	}

	int ks = k.size() - 1;
	int last = k[ks];
	vector<pii> res;
	set<pii> check;

	for(int i = 0; i < ks; i++) {
		for(int j = i + 1; j < ks; j++)	 {
			pii tmpv = mp(min(k[i], k[j]), max(k[i], k[j]));
			if(k[i] + k[j] == last && check.find(tmpv) == check.end())	{
				res.pb(tmpv);
				check.insert(tmpv);
			} 
		}
	}

	sort(all(res), [](pii p1, pii p2) {
			return p1.f == p2.f ? p1.s < p2.s : p1.f < p2.f;
	});

	for(int i = 0; i < res.size(); i++) {
		cout << res[i].f << " " << res[i].s << "\n";
	}
	cout << res.size() << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
