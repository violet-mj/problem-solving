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
	int an, bn;		
	cin >> an;
	vector<vector<int>> ak(101);
	vector<vector<int>> bk(101);
	vector<int> as(an);
	for(int i = 0; i < an; i++) {
		cin >> as[i];
		ak[as[i]].pb(i);
	}
	cin >> bn;
	vector<int> bs(bn);
	for(int i = 0; i < bn; i++){
		cin >> bs[i];
		bk[bs[i]].pb(i);
	} 
	vector<int> res;
	int inita = -1;
	int initb = -1;
	int i = 100;
	while(i >= 1) {
		debug(i);
		if(ak.size() == 0 || bk.size() == 0)	{
			i--; continue;
		}
		int aIdx = upper_bound(all(ak[i]), inita) - ak[i].begin();
		int bIdx = upper_bound(all(bk[i]), initb) - bk[i].begin();
		if(aIdx >= ak[i].size() || bIdx >= bk[i].size()) {
			i--; continue;
		}
		if(ak[i][aIdx] < inita || bk[i][bIdx] < initb || aIdx >= ak[i].size() || bIdx >= bk[i].size()) {
			i--; continue;
		}
		res.pb(i);
		inita = ak[i][aIdx];
		initb = bk[i][bIdx];
		i = 100;
	}

	cout << res.size() << "\n";
	for(int i = 0; i < res.size(); i++) {
		cout << res[i] << " \n"[i == res.size() -1];
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
