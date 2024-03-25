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
	int n, q;
	cin >> n >> q;
	set<int> sets[n];
	vector<int> mapping(n);
	int count, tmp;

	for(int i = 0; i < n; i++) {
		mapping[i] = i;	
	}

	for(int i = 0; i < n; i++) {
		cin >> count;
		
		for(int j = 0; j < count; j++) {
			cin >> tmp;
			sets[i].insert(tmp);
		}
	}

	int a, b, cmd;
	for(int i = 0; i < q; i++) {
		cin >> cmd;		
		if(cmd == 1) {
			cin >> a >> b;	
		  a--; b--;
		  int ma = mapping[a];
		  int mb = mapping[b];
		  if(sets[mb].size() > sets[ma].size()) {
			  for(auto i = sets[ma].begin(); i != sets[ma].end(); i++) {
				  sets[mb].insert(*i);
			  }
			  sets[ma].clear();
			  swap(mapping[a], mapping[b]);
		  } else {
			  for(auto i = sets[mb].begin(); i != sets[mb].end(); i++) {
				  sets[ma].insert(*i);
			  }
			  sets[mb].clear();
			}
		} else {
			cin >> a;	
			a--;
			cout << sets[mapping[a]].size() << "\n";
		} 
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
