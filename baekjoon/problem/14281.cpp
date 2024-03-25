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
	int n;	cin >> n;
	vector<lint> vs1(n);
	for(int i = 0; i < n; i++) cin >> vs1[i];

	lint res1 = 0LL;
	
	for(int z = 0; z < 5000; z++) {
	  for(int i = 1; i < n - 1; i++) {
		  if(vs1[i - 1] + vs1[i + 1] < vs1[i] * 2) {
			  lint diff = (vs1[i] * 2 - vs1[i-1] - vs1[i+1]);
			  lint diff2 = (diff + 1) / 2;
			  vs1[i] -= diff2;
			  res1 += diff2;
		  }
	  }
		debug(vs1);
	}
	cout << res1 << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
