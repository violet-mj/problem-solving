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
	vector<pii> times(n);		
	for(int i = 0; i < n; i++) {
		cin >> times[i].f >> times[i].s;
	}

	int max_ = -1;
	for(int i = 0; i < 24; i++) {
		int res = 0;
		for(int j = 0; j < times.size(); j++)	 {
			int currTime = (times[j].second + i) % 24;
			if(currTime >= 9 && currTime < 18) {
				res += times[j].f;	
			}
		}
		max_ = max(res, max_);
	}

	cout << max_ << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
