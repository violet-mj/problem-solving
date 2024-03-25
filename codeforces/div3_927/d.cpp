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

typedef pair<string, string> pss;

void solve() {
	int n; cin >> n;	
	char trump; cin >> trump;
	vector<string> v(2 * n);
	map<char, vector<string>> m;
	for(int i = 0; i < 2 * n; i++) {
		cin >> v[i];
		m[v[i][1]].pb(v[i]);
	}

	string CDHS = "CDHS";
	vector<pss> res;

	for(auto i = m.begin(); i!=m.end(); i++) {
		// debug(i->s);
	}

	int l = 0;
	sort(all(m[trump]));
	int trumpSize = m[trump].size();

	for(int i = 0; i < 4; i++) {
		if(CDHS[i] == trump) continue;
		sort(all(m[CDHS[i]]));
		int notTrumpSize = m[CDHS[i]].size();
		for(int j = 1; j < m[CDHS[i]].size(); j+=2) {
			res.pb(mp(m[CDHS[i]][j - 1], m[CDHS[i]][j]));
		}
		if(m[CDHS[i]].size() % 2 == 1) {
			if(l >= trumpSize) {
				cout << "IMPOSSIBLE\n";
				return;
			}
			res.pb(mp(m[CDHS[i]][notTrumpSize - 1], m[trump][l++]));
		}
	}

	if((trumpSize - l) % 2 == 1) {
		cout << "IMPOSSIBLE\n";
		return;
	}

	for(int i = l; i < trumpSize; i+=2) {
		res.pb(mp(m[trump][i], m[trump][i+1]));
	}

	for(int i = 0; i < res.size(); i++) {
		cout << res[i].f << " " << res[i].s << "\n";
	}
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) solve();
}
