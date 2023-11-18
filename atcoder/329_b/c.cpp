
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
	string s;		
	cin >> n >> s;

	vector<int> check(26, 0);
	char init = s[0];
	int cnt = 1;
	for(int i = 1; i < s.size(); i++)	 {
		if(init == s[i]) {
			cnt++;	
		} else {
			check[init - 'a'] = max(check[init - 'a'], cnt);
			init = s[i];
			cnt = 1;
		}
	}
	check[init - 'a'] = max(check[init - 'a'], cnt);

	int res = 0;
	for(int i = 0; i < 26; i++) {
		res += check[i];
	}
	
	cout << res << "\n";
}


int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
