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
	string s;		
	cin >> s;
	vector<pair<int, char>> upper;
	vector<pair<int, char>> lower;
	vector<pair<int, char>> command;

	for(int i = 0; i < s.size(); i++) {
		if(s[i] == 'B') {
			if(upper.size() == 0) continue;
			upper.pop_back();
		} else if(s[i] == 'b') {
			if(lower.size() == 0) continue;
			lower.pop_back();
		}else if(isupper(s[i])) {
			upper.pb({i, s[i]});	
		} else {
			lower.pb({i, s[i]});
		}
	}


	for(int i = 0; i < upper.size(); i++) {
		lower.pb(upper[i]);
	}

	sort(all(lower), [](pair<int, char> p1,pair<int, char> p2) {
			return p1.f < p2.f;	
	});

	for(int i = 0; i < lower.size(); i++) {
		cout << lower[i].s;
	}
	cout << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) solve();
}
