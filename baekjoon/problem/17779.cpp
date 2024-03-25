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
	int n;	cin >> n;
	vector<int> ai(n);		
	vector<int> bi(n);		
	vector<int> ki(n);
	for(int i = 0; i < n; i++) cin >> ai[i];
	for(int i = 0; i < n; i++) cin >> bi[i];
	for(int i = 0; i < n; i++) {
		string s; cin >> s;
		string tmp = "";
		for(int i = 0; i < s.size(); i++) {
			if(s[i] == '.')	continue;
			tmp+=s[i];
		}
		ki[i] = stoi(tmp);
	}
	lint res = 0LL;
		
	for(int i = 0; i < n; i++) {
		int r1 = (ai[i] * ki[i] / 10) - bi[i];
		int r2 = ai[i] - (bi[i] * ki[i] / 10);
		res += (lint) max(r1, r2);
		debug(res);
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
