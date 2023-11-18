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
	int n;	
	cin >> n;
	map<int, int> m;
	vector<int> values(n);
	for(int i = 0; i < n; i++) {
		cin >> values[i];
		m[values[i]]++;
	}
	debug(m);
	lint res = 0;
	for(auto i = m.begin(); i != m.end(); i++) {
		int v = i->second;	
		res += (lint)v * (v - 1) / 2;
	}

	debug(res);

	for(int i = 0; i < n; i++) {
		if(values[i] == 1) {
			res += m[2];
		}
	}
	cout << res << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) solve();
}
