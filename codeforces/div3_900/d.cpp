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
	int n, k, q;
	string initS;
	cin >> n >> k;			
	cin >> initS;
	vector<int> left(k+1);
	vector<int> right(k+1);
	
	for(int i = 0; i < k; i++) {
		cin >> left[i];
		left[i]--;
	}
	for(int i = 0; i < k; i++) {
		cin >> right[i];
		right[i]--;
	}		
	
	cin >> q;
	vector<int> coords;
	vector<pii> items(q);
	vector<int> lFind(q);

	int x;
	for(int i = 0; i < q; i++) {
		cin >> x;
		int xLower = lower_bound(all(left), x) - left.begin();
		int l = min(x, left[xLower] + right[xLower] - x);
		int r = max(x, left[xLower] + right[xLower] - x);
		items[i] = mp(l, r);
		lFind[i] = xLower;
		coords.pb(l); coords.pb(r);
	}
	sort(all(coords)); coords.erase(unique(all(coords)), coords.end());
	vector<int> mos(coords.size()+1, 0);

	for(int i = 0; i < q; i++) {
		int f = items[i].f;	
		int s = items[i].s;	
		int fIdx = lower_bound(all(coords), f) - coords.begin();
		int sIdx = lower_bound(all(coords), s) - coords.begin();
		mos[fIdx]++;
		mos[sIdx]--;	
	}

	for(int i = 1;i < mos.size(); i++){
		mos[i]+=mos[i-1];
	}

	if(coords.size() >= 1) {
	  int s = coords[0];
	  int fIdx = lower_bound(all(coords), s) - coords.begin();
	  if(mos[fIdx]%2==0){
			  for(int i = 0; i < s; i++)	 {
				  cout << initS[i];
			  }
	  } else {
			  for(int i = s-1; i >= 0; i++)	 {
				  cout << initS[i];
			  }
	  }
	}

	for(int i = 0; i < coords.size() - 1; i++) {
		int f = coords[i];
		int s = coords[i+1];
		int fIdx = lower_bound(all(coords), f) - coords.begin();
		if(mos[fIdx]%2==0){
				for(int i = f; i < s; i++)	 {
					cout << initS[i];
				}
		} else {
				for(int i = s-1; i >= f; i++)	 {
					cout << initS[i];
				}
		}
	}

	if(coords.size() >= 1) {
	  int f = coords[coords.size() - 1];
	  int fIdx = lower_bound(all(coords), f) - coords.begin();
	  if(mos[fIdx]%2==0){
			  for(int i = f; i < n; i++)	 {
				  cout << initS[i];
			  }
	  } else {
			  for(int i = n - 1; i >= f; i++)	 {
				  cout << initS[i];
			  }
	  }
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
