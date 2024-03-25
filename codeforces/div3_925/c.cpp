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
	vector<int> v(n);
	for(int i = 0; i < n; i++) cin >> v[i];

		int init = v[0];
		int last = v[n - 1];
		int f = 0;
		int s = n - 1;
		for(int i = 0; i < n; i++) {
			if(init == v[i]) {
				f++;		
			} else {
				break;	
			}
		}

		if(f == n) {
			cout << 0 << "\n";
			return;
		}

		for(int i = n - 1; i >= 0; i--) {
			if(init == v[i])	 {
				s--;	
			} else {
				break;	
			}
		}

		int f1 = 0;
		int s1 = n-1;

		for(int i = 0; i < n; i++) {
			if(last == v[i]) {
				f1++;		
			} else {
				break;	
			}
		}


		for(int i = n - 1; i >= 0; i--) {
			if(last == v[i])	 {
				s1--;	
			} else {
				break;	
			}
		}
		if(s == -1) {
			cout << 0 << "\n";
		}
		debug(f, s);

		cout << min(s - f + 1, s1 - f1 + 1) << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) 
	solve();
}
