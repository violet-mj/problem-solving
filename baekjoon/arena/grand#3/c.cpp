
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
	vector<int> fruits(n);
	for(int i = 0; i < n; i++) cin >> fruits[i];
	int l = 0, r = 0;
	int type = 1;
	vector<int> fruitCnt(10, 0);
	fruitCnt[fruits[0]]++;
	int cnt = 1;
	int max_ = cnt;
	while(1) {
		r++;
		if(r >= n) break;
		if(++fruitCnt[fruits[r]] == 1) {
			type++;	
		}
		cnt++;
		while(type >= 3) {
			debug(fruitCnt);
			cnt--;
			if(--fruitCnt[fruits[l++]] == 0) {
				type--;	
			}
		}
		max_ = max(cnt, max_);
		debug(max_, l, r);
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
