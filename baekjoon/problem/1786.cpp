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
	string t, p;			
	getline(cin, t);
	getline(cin, p);
	int ps = p.size();

	vector<int> preCal(ps, 0);

	int curr = 0;
	int j = 0;
	for(int i = 1, j = 0; i < ps; i++) {
		while(j > 0 && p[i] != p[j]) j = preCal[j - 1];
		if(p[i] == p[j]) preCal[i] = ++j;
	}

	debug(preCal);
	
	int cnt = 0;
	vector<int> res;

	for(int i = 0, j = 0; i < t.size(); i++) {
		while(j > 0 && t[i] != p[j]) j = preCal[j - 1];
		if(t[i] == p[j]) {
			if(j == ps - 1) {
				cnt++;	
				res.pb(i + 2 - ps);
				j = preCal[j];
			} else {
				j++;
			}
		}
	}

	cout << cnt << "\n";
	for(int i = 0; i < res.size(); i++) {
		cout << res[i] << " \n"[i == res.size() - 1];
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
