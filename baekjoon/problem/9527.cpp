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
	vector<int> dice(n);
	map<int, int> m;
	for(int i = 0; i < n; i++) {
		cin >> dice[i];
		m[dice[i]]++;
	}

	int cnt = 0;

	while(m.size() > 0)  {
		vector<int> remove;	
		vector<int> stk;
		for(auto i = m.begin(); i != m.end(); i++) {
			int num = i->first;	
			while(i->second > 0){
			  if(num == 0) {
				  cnt++;
			  } else {
				  if(num >= stk.size())		 {
					  stk.pb(num);
				  } else {
						break;
				  }
			  }
				i->second--;
			}
			if(i->second == 0) remove.pb(num);
		}
		cnt++;
		for(auto i: remove) {
			m.erase(i);
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
