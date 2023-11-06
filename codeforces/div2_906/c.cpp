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
	string s;

	cin >> n >> s;

	int l = 0;
	int r = n - 1;

	vector<int> res;

	int zero = 0;
	int one = 0;

	for(int i = 0; i < n; i++) {
		if(s[i] == '0') {
			zero++;	
		}	else {
			one++;	
		}
	}

	if(zero != one) {
		cout << -1 << "\n";
		return;
	}

	int cnt = 0;
	while(l < r) {
		debug(l, r, s);
		if(s[l] != s[r]) {
			l++;	
			r--;
		}	else {
			if(s[l] == '0') {
				s.insert(r+1, "01");
				res.pb(r+1);
				l++;
				r++;
			} else {
				s.insert(l, "01");
				res.pb(l);
				l++;
				r++;
			}	
		}
	}


	cout << res.size() << "\n";
	for(int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
	cout << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) 
	solve();
}
