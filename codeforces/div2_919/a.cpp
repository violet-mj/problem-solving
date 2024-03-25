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
	int n; cin >> n;				

	int min_ = 1;
	int max_ = 1e9; 


	set<int> c;
	for(int i = 0; i < n; i++) {
		int a, x; cin >> a >> x;	

		
		if(a == 1) {
			min_ = max(min_, x);
		} else if(a == 2) {
			max_ = min(max_, x);
		} else {
			c.insert(x);
		}
	}


	if(min_ > max_)	 {
		cout << 0 << "\n";	
	} else {
		int cnt = 0;
		for(auto i = c.begin(); i != c.end(); i++)	 {
			int curr = *i;
			if(curr >= min_ && curr <= max_) {
				cnt++;	
			}
		}
		cout << max_ - min_ - cnt + 1<< "\n"; 
	}
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) solve();
}
