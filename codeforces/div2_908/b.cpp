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
	vector<int> values(n);
	map<int, int> m;
	for(int i = 0; i < n; i++) {
		cin >> values[i];
		m[values[i]]++;
	}
	vector<int> res(n, 1);

	bool two = true;
	bool three = true;
	set<int> sss;
	
	for(int i = 0; i < n; i++) {
		if(m[values[i]] <= 1)	{
			continue;
		} else {
			if(sss.find(values[i]) != sss.end()) continue;
			if(two) {
				res[i] = 2;	
				sss.insert(values[i]);
				two = false;
				continue;
			} 

			if(three) {
				res[i] =3;
				sss.insert(values[i]);
				three = false;
				continue;
			}
		}
	}

	if(two || three) {
		cout << "-1\n" << "\n";
		return;
	}

	for(int i = 0; i < n ; i++) {
		cout << res[i] << " \n"[i == n - 1];
	}
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) 
		solve();
}
