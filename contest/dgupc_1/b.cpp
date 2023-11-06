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

	vector<int> value(n);

	for(int i = 0; i < n; i++) cin >> value[i];

	int cnt = value[0] > 0 ? 1 : 0;
	int max_ = cnt;

	for(int i = 1; i < n; i++) {
		if(value[i] == 0 && value[i-1] == 0)	 {
			cnt = 0;
		} else if(value[i] > 0 && value[i-1] >= 0) {
			cnt++;	
			max_ = max(max_, cnt);
		} else {
			continue;	
		}
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
