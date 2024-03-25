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
	lint n; cin >> n;		
	n--;

	if(n == 0) {
		cout << 0 << "\n"	;
		return;
	}
	lint v = 1LL;
	string res = "";
	const int alpha[5] = {0, 2, 4, 6, 8};
	for(int i = 0; i < 22; i++) {
		lint curr = n % 5LL;	
		res += to_string(curr);
		n /= 5LL;
	}
	reverse(all(res));
	int cnt = 0;

	for(int i = 0; i < res.size(); i++) {
		if(res[i] != '0')	 {
			cnt = i;	
			break;
		}
	}

	string k = "";

	for(int i = cnt; i < res.size(); i++) {
		k += to_string(alpha[res[i] - '0']);
	}

	cout << k << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
