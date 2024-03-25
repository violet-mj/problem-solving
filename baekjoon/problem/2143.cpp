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
	map<lint, int> ma;
	map<lint, int> mb;
	int t;
	cin >> t;
	int na; cin >> na;
	vector<int> av(na+1,0);
	vector<lint> prea(na+1, 0);
	for(int i = 1; i <= na; i++) {
		cin >> av[i];
		prea[i] = prea[i-1] + av[i];
	}
	int nb; cin >> nb;
	vector<int> bv(nb+1, 0);
	vector<lint> preb(nb+1,0);
	for(int i = 1; i <= nb; i++) {
		cin >> bv[i];
		preb[i] = preb[i-1] + bv[i];
	}

	for(int i = 1; i <= na; i++) {
		for(int j = i; j <= na; j++)	 {
			lint partial = prea[j] - prea[i-1];
			ma[partial]++;
		}
	}

	for(int i = 1; i <= nb; i++) {
		for(int j = i; j <= nb; j++)	 {
			lint partial = preb[j] - preb[i-1];
			mb[partial]++;
		}
	}
	lint cnt = 0;
	debug(ma);
	debug(mb);

	for(auto i = ma.begin(); i != ma.end(); i++) {
		lint valuea = i->f;		
		lint cnta = i->s;
		if(mb.find(t-valuea) != mb.end()) {
			cnt += cnta * mb[t - valuea];
		}
	}

	cout << cnt << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
